# Rapport de Projet

## Sommaire

1. [Introduction](#i-introduction)
2. [Outils Utilisés](#ii-outils-utilisés)
3. [Participations des membres](#iii-participations-des-membres)
4. [Organisation](#iv-organisation)
5. [Bilan](#v-bilan)

---

<br/>

## I. Introduction

Le sujet traité fut la creation d'un outil, qui au travers d'un "mini" langage permet de tracer et visualiser des graphes de fonctions mathématiques, projet que nous avons nommé MathematiC. <br/><br/>
![Image Interface](img/TestInterface.png) *Interface du programme*

---

<br/>

## II. Outils utilisés

Comme vu au long du cours de Théorie des Langages, nous avons utilisés le C et C++ comme base du projet, en programmant la partie "langage" en flex/bison (sans utiliser de racourcis comme le Javascript). Afin de coder la partie graphique nous avons utilisé SDL2 et OpenGL3, le tout à l'aide du framework [Dear ImGui](https://github.com/ocornut/imgui).

En plus de ce framework et de ces langages, nous avons bien évidemment utilisé `git` ainsi que GitHub pour gérer le versioning, ainsi que `make` pour compiler notre projet (on ne citera pas les éditeurs de texte tel vim utilisé par l'équipe pour programmer). Il est important de noter que nous avons aussi utilisé le framework [Catch2](https://github.com/catchorg/Catch2) afin de réaliser des tests unitaires. Il faut aussi noter que l'on a utilisé la fonctionnalité Issue de GitHub afin de remonter les erreurs aux personnes capable de les regarder comme sur cette [issue](https://github.com/HugoMartel/Projet_ThL/issues/1), ou [celle-ci](https://github.com/HugoMartel/Projet_ThL/issues/2).

Enfin, nous avons utilisé [Doxygen](https://www.doxygen.nl/index.html) afin de réaliser la documentation des diverses fonctions de notre projet.

<br/>

---

## III. Participations des membres

[Louis Ducrocq](https://github.com/Louis-duc) et [Lionel Smets](https://github.com/LionelSts) commencèrent par travailler sur la partie langage, en posant les fondements du flex et du bison pendant que [Louis Manouvriez](https://github.com/Spac3Drunk) et [Théodore Martin](https://github.com/TT-txt) commencèrent la partie front-end du projet en codant uniquement sur SDL2 sans framework, alors que [Hugo Martel](https://github.com/HugoMartel) travaillait sur la compilation et les dependances.

Après une semaine et une prise de conscience, nous avons commencé à utiliser un framework pour la partie front-end: nous avons donc commené à coder l'interface à l'aide du framework [nano-gui SDL](https://github.com/dalerank/nanogui-sdl). Hugo commença alors à travailler sur le front et le fichier `CMakeList.txt` associé, mais après plusieurs semaines de travail sur ce framework nous avons découvert Dear Imgui, et avons décidé de changer pour utiliser celui-ci qui nous permettait de régler un grand nombre de problème (des inputs de textes multilines qui n'étaient pas programmés, changement de taille, etc..). Alors que Louis D et Lionel travaillait encore sur le langage, Hugo aida Louis M et Théodore à reprogrammer la Makefile (le changement de framework obligea de passer d'une compilation avec CMake à une compilation avec make). Une fois que le projet recompila, Louis D créa alors les fonctions nécessaires pour l'affichage des courbes et leur personalisation, pendant que Théodore programma l'affichage de la fenètre, les fonctions pour ouvrir et enregistrer un fichier, zone de code, etc...

Une fois à la fin du projet, il y a eu une semaine de mise en commun où toutes les branches du git ont été fusionnées pour faire le lien entre toutes les parties, afin d'obtenir le projet final. Cette dernière phase entraine aussi une longue partie de debug, réalisée à l'aide de tests unitaire et du framework cité dans [la partie II](#ii-outils-utilisés).

<br/>

---

## IV. Organisation

Concernant l'organisation du projet nous avons pendant la première séance réalisé une réunion afin de séparer le projet en différentes tâches bien précises afin de se les répartir. Nous avons pu ainsi attribuer les rôles de chacun et nous avons décider de créer un serveur discord afin de tenir compte de nos avancées et ou de nos retards. Nous nous sommes aussi tenu à un rythme de une réunion hébdomadaire afin de bien s'assurer que tous le monde réussissait à progresser dans le projet.

Cette façon de faire nous a donc permis à tous d'avoir une vue d'ensemble sur l'avancée global du projet du toute la periode de production. Elle nous permettait aussi de bien garder à l'esprit les deadlines de chaque partie.

---

## V. Bilan

Ce projet ne fut clairement pas le plus simple que nous ayons eu à mener. Les problèmes se sont enchainés (comme avec le changement de framework), des segmentation fault et bien d'autres. Il fut aussi particulièrement intense: nous avons fait face une période de crunch sur les deux dernières semaines du projet pour tout terminer et tout debugger afin de rendre le projet en temps et en heure. Celui-ci nous a permis d'expérimenter avec de nouveaux frameworks en C/C++, ainsi qu'une première expérience pour certains avec un framework de test unitaire. Ce projet nous a aussi permis de consolider nos acquis avec [Doxygen](https://www.doxygen.nl/index.html) pour générer la documentation de notre projet. Enfin il nous a aussi permis d'appliquer concrètement ce que nous avions appris lors des cours de Théorie des Langages, démontrant ainsi toute son importance.
