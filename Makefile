# Les différents répertoires
HEADDIR := ./include
BINDIR  := ./bin
OBJDIR	:= ./obj
SRCDIR 	:= ./src

# Options de compilation
# TODO: Ajouter -Werror et -Wextra a la fin et enleverles -Wno
CFLAGS = -g -Wall -Wno-unused-variable -O2 -std=c99
CC 	= gcc
EXEC = $(BINDIR)/lzw

# Emplacement des fichiers
SOURCES := $(wildcard ${SRCDIR}/*.c)
HEADERS := $(wildcard ${HEADDIR}/*.h)
OBJ 		:= $(SOURCES:src$(EXEC)/%.c=obj/%.o)

# Makefile
all: $(EXEC)

# Création de l'exécutable
$(EXEC): $(OBJ)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(EXEC) $^ $(CFLAGS)
	@echo "L'éxecutable a été crée."
	@echo "Utilisation: /bin/lzw [options] <chemin_fichier>"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

# TODO
valgrind: 
	@echo "Retrouver le résultat de Valgrind dans le fichier valgrind-results.txt"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-results.txt $(EXEC) 

# Nettoyage complet
clean:
	@rm -rf $(OBJDIR) $(BINDIR) $(DOCDIR) ../$(DIST).tar.xz valgrind-results.txt
	@echo "Nettoyage des fichiers et dossier inutiles effectué."
