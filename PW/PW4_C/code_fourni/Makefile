
SHELL = /bin/bash

INSTALL = cp
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA    = $(INSTALL)

#########################################################
# Compiler and options
#########################################################

CC = gcc
CPP = gcc -E

INCDIR = -I.

CPPFLAGS = $(INCDIR)
#CPPFLAGS = $(INCDIR) -DHAVE_CONFIG
#CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500 -DHAVE_CONFIG
#CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500 -DNDEBUG

# -fPIC pour que les .o générés puissent être utilisés sur diverses
# architectures
CFLAGS = -g -Wall -Wextra -pedantic -std=c99 -fPIC
#CFLAGS = -O -Wall -Wextra -pedantic -std=c99 -fPIC


#LIBS = -ljpeg -lXaw -lm
LIBS = 

#LDFLAGS = -L/usr/local/X11R6/lib -L../jpeg $(LIBS)
LDFLAGS = $(LIBS)



#########################################################
# Common prefix for installation directories.
#########################################################

#prefix = /usr/local
prefix = .
exec_prefix = ${prefix}

bindir  = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec

libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
includedir = ${prefix}/include
mandir = ${prefix}/man

srcdir  = .


#########################################################
# bin, sources, ...
#########################################################

BIN1 = exerciceA
SRC1 = exerciceA.c
OBJ1 = $(subst .c,.o,$(SRC1))
DFILES1 = $(subst .c,.d,$(SRC1))

BIN2 = exerciceB
SRC2 = exerciceB.c
OBJ2 = $(subst .c,.o,$(SRC2))
DFILES2 = $(subst .c,.d,$(SRC2))

BIN3 = exerciceC
SRC3 = exerciceC.c
OBJ3 = $(subst .c,.o,$(SRC3))
DFILES3 = $(subst .c,.d,$(SRC3))

BIN4 = exerciceD
SRC4 = exerciceD.c
OBJ4 = $(subst .c,.o,$(SRC4))
DFILES4 = $(subst .c,.d,$(SRC4))

BIN5 = exerciceE
SRC5 = exerciceE.c
OBJ5 = $(subst .c,.o,$(SRC5))
DFILES5 = $(subst .c,.d,$(SRC5))

BIN6 = exerciceF
SRC6 = exerciceF.c
OBJ6 = $(subst .c,.o,$(SRC6))
DFILES6 = $(subst .c,.d,$(SRC6))

BIN7 = exerciceG
SRC7 = exerciceG.c
OBJ7 = $(subst .c,.o,$(SRC7))
DFILES7 = $(subst .c,.d,$(SRC7))

BIN8 = exerciceH
SRC8 = exerciceH.c
OBJ8 = $(subst .c,.o,$(SRC8))
DFILES8 = $(subst .c,.d,$(SRC8))

BIN9 = exerciceI
SRC9 = exerciceI.c
OBJ9 = $(subst .c,.o,$(SRC9))
DFILES9 = $(subst .c,.d,$(SRC9))


BIN = $(BIN1) $(BIN2) $(BIN3) $(BIN4) $(BIN5) $(BIN6) $(BIN7) $(BIN8) $(BIN9)
SRC = $(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5) $(SRC6) $(SRC7) $(SRC8) $(SRC9)
OBJ = $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9)
DFILES = $(DFILES1) $(DFILES2) $(DFILES3) $(DFILES4) $(DFILES5) $(DFILES6) $(DFILES7) $(DFILES8) $(DFILES9)


#########################################################
# explicite rules
#########################################################
explain:
	@echo "Utilisation de la commande make"
	@echo "Pour tout compiler :"
	@echo "   $$ make all"
	@echo "pour compiler un seul exerice, par exemple exerciceE :"
	@echo "   $$ make exerciceE"

all: $(BIN)

$(BIN1): $(OBJ1)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ1) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN2): $(OBJ2)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ2) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN3): $(OBJ3)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ3) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN4): $(OBJ4)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ4) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN5): $(OBJ5)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ5) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN6): $(OBJ6)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ6) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN7): $(OBJ7)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ7) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN8): $(OBJ8)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ8) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="

$(BIN9): $(OBJ9)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ9) $(LDFLAGS)
#	@echo "end creating" $@ "======================================="


#########################################################
# generic rules
#########################################################
install:
	@echo install to do

uninstall:
	@echo uninstall to do

clean:
	@echo "deleting" $(OBJ) $(DFILES)
	@$(RM) $(OBJ) $(DFILES)

distclean: clean
	@echo "deleting" $(BIN)
	@$(RM) $(BIN)

mostlyclean:
	@echo mostlyclean to do

maintainer-clean:
	@echo maintainer-clean to do

TAGS:
	@echo TAGS to do

info:
	@echo info to do


#########################################################
# Implicite rules
#########################################################

#.SILENT:

.SUFFIXES : .c .o .d

%.o : %.c
	@echo 'compiling' $< ;\
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@ ;

%.d : %.c
	@$(SHELL) -ec '$(CC) -MM $(CPPFLAGS) $< \
	   | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@' ;

# include dependance files
-include $(DFILES)
