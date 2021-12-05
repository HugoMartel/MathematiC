#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# You will need SDL2 (http://www.libsdl.org):
# Linux:
#   apt-get install libsdl2-dev
# Mac OS X:
#   brew install sdl2
# MSYS2:
#   pacman -S mingw-w64-i686-SDL2
#

#CXX = g++
#CXX = clang++

EXE = MathematiC
IMGUI_DIR = ./lib/imgui
IMPLOT_DIR = ./lib/implot

INC := include
SRC := src
INC := include
LANG := language
GEN := generated
BUILD := build

# SRC
SOURCES = $(SRC)/test.cpp
# IMGUI_DIR
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
# IMGUI_DIR/backends
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
SOURCES += $(IMPLOT_DIR)/implot.cpp $(IMPLOT_DIR)/implot_items.cpp
SOURCES += $(INC)/zenity.cpp $(INC)/interface.cpp

# Get generated objects names
OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
CLEANABLE = $(EXE) $(OBJS) $(BUILD)/lexer.flex.o $(BUILD)/parser.bison.o $(BUILD)/lang $(GEN)/*.cpp $(GEN)/*.hpp

# Get current config-d -p
UNAME_S := $(shell uname -s)


## IMGUI HEADERS && OURS
CXXFLAGS = -Wall -Wextra -Wformat --std=c++17
LIBFLAGS = -I $(IMGUI_DIR) -I $(IMGUI_DIR)/backends -I $(IMPLOT_DIR) -I ./include
# Linker
LDFLAGS := -g
#LDFLAGS := -O3
# Flex
LFLAGS = -v
LFLAGS += -d -p
# Bison /!\ 3.7.6 flags: -Wcounterexamples --color=yes
BFLAGS = --warnings=all --defines -v
BFLAGS += -t
LIBS =
ZENITY =


##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"

##----------##
##  OPENGL  ##
##----------##
	LINUX_GL_LIBS = -lGL
## This assumes a GL ES library available in the system, e.g. libGLESv2.so
# CXXFLAGS += -DIMGUI_IMPL_OPENGL_ES2
# LINUX_GL_LIBS = -lGLESv2
## If you're on a Raspberry Pi and want to use the legacy drivers,
## use the following instead:
# LINUX_GL_LIBS = -L/opt/vc/lib -lbrcmGLESv2

	LIBS += $(LINUX_GL_LIBS) -ldl `sdl2-config --libs`

# Check for zenity
	ZENITY = Zenity version :
	ZENITY += $(shell zenity --version)

	LIBFLAGS += `sdl2-config --cflags`
	CFLAGS = $(CXXFLAGS) $(LIBFLAGS)

endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo `sdl2-config --libs`
	LIBS += -L/usr/local/lib -L/opt/local/lib

	LIBFLAGS += `sdl2-config --cflags`
	LIBFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = -W -Wextra -Wformat $(LIBFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lgdi32 -lopengl32 -limm32 `pkg-config --static --libs sdl2`

	LIBFLAGS += `pkg-config --cflags sdl2`
	CFLAGS = -W -Wextra -Wformat $(LIBFLAGS)
endif


##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

# Default rule
all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

run: $(EXE)
	./$(EXE)

# Test File
$(BUILD)/test.o: $(SRC)/test.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@

# Main File

# Unit tests File


# Include Files
$(BUILD)/%.o: $(INC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Bison/Flex Files
$(GEN)/parser.bison.cpp: $(LANG)/parser.y
	bison $(BFLAGS) -o $@ $<

$(GEN)/lexer.flex.cpp: $(LANG)/lexer.l
	flex $(LFLAGS) -o $@ $<

$(BUILD)/%.o: $(GEN)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Imgui Files
$(BUILD)/%.o: $(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@

$(BUILD)/%.o: $(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@

# Implot Files
$(BUILD)/%.o: $(IMPLOT_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build Executable File
$(EXE): $(OBJS)
	@echo $(OBJS)
	@echo $(ZENITY)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

# Build Bison/Flex exe
lang: $(BUILD)/parser.bison.o $(BUILD)/lexer.flex.o
	@echo Building Bison/Flex
	$(CXX) -o $(BUILD)/lang $^
	$(BUILD)/$@ $(LANG)/test.txt

clean:
	rm -vf $(CLEANABLE)
