#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# You will need SDL2 (http://www.libsdl.org):
# Linux:
#   apt-get install libsdl2-dev bison flex zenity
#   dnf install sdl2-devel bison flex zenity
#   pacman -S sdl2 bison flex zenity
# Mac OS X:
#   brew install sdl2
# MSYS2:
#   pacman -S mingw-w64-i686-SDL2
#

#CXX = g++
#CXX = clang++

EXE = MathematiC
TEST = test
IMGUI_DIR = ./lib/imgui
IMPLOT_DIR = ./lib/implot

INC := include
SRC := src
INC := include
LANG := language
GEN := generated
BUILD := build


# BISON/FLEX DIR
SOURCES = $(GEN)/parser.yy.cpp $(GEN)/lexer.yy.cpp
# IMGUI_DIR
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
# IMGUI_DIR/backends
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
# IMPLOT DIR
SOURCES += $(IMPLOT_DIR)/implot.cpp $(IMPLOT_DIR)/implot_items.cpp
# INCLUDE DIR
SOURCES += $(INC)/zenity.cpp $(INC)/interface.cpp


# Get generated objects names
OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))

CLEANABLE = $(EXE) $(OBJS) $(GEN)/paser.yy.* $(GEN)/lexer.yy.* $(BUILD)/main.o $(BUILD)/unit-tests.o


# Get current config-d -p
UNAME_S := $(shell uname -s)


## IMGUI HEADERS && OURS
CXXFLAGS = -Wall -Wextra -Wformat --std=c++17
LIBFLAGS = -I $(IMGUI_DIR) -I $(IMGUI_DIR)/backends -I $(IMPLOT_DIR) -I $(INC) -I $(GEN)
# Linker
LDFLAGS := -g
#LDFLAGS := -O3
# Flex
LFLAGS = -v --header-file=$(GEN)/lexer.yy.hpp
LFLAGS += -d -p
# Bison /!\ 3.7.6 flags: -Wcounterexamples --color=yes
BFLAGS = --warnings=all --defines=$(GEN)/parser.yy.hpp -v
BFLAGS += -t --debug
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

	LIBS += $(LINUX_GL_LIBS) -ldl $(shell sdl2-config --libs)

# Check for zenity
	ZENITY = Zenity version :
	ZENITY += $(shell zenity --version)

	LIBFLAGS += $(shell sdl2-config --cflags)
	CFLAGS = $(CXXFLAGS) $(LIBFLAGS)

endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo $(shell sdl2-config --libs)
	LIBS += -L/usr/local/lib -L/opt/local/lib

	LIBFLAGS += $(shell sdl2-config --cflags)
	LIBFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = -W -Wextra -Wformat $(LIBFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lgdi32 -lopengl32 -limm32 $(shell pkg-config --static --libs sdl2)

	LIBFLAGS += $(shell pkg-config --cflags sdl2)
	CFLAGS = -W -Wextra -Wformat $(LIBFLAGS)
endif


##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

# Default rule
all: bison flex $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

run: $(EXE)
	./$(EXE)


# Main File
$(BUILD)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@

# Unit tests File
$(BUILD)/unit-tests.o: $(SRC)/unit-tests.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@


# Bison/Flex Files
bison: $(LANG)/parser.y
	bison $(BFLAGS) -o $(GEN)/parser.yy.cpp $<

flex: $(LANG)/lexer.l
	flex $(LFLAGS) -o $(GEN)/lexer.yy.cpp $<

$(BUILD)/%.o: $(GEN)/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@


# Include Files
$(BUILD)/%.o: $(INC)/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@


# Imgui Files
$(BUILD)/%.o: $(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@

$(BUILD)/%.o: $(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@


# Implot Files
$(BUILD)/%.o: $(IMPLOT_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< -o $@


# Build Executable File
$(EXE): $(OBJS) $(SRC)/main.cpp
	@echo $(OBJS)
	@echo $(ZENITY)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)
	
$(TEST): lang $(OBJS) $(SRC)/unit-tests.cpp
	@echo Unit Tests
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)
	./$(TEST)


# Build Bison/Flex exe
lang: bison flex
	@echo Generating from Bison/Flex

clean:
	rm -vf $(CLEANABLE)

