# weirdtetris

NAME = weirdtetris
VERSION = 0.1
SRC = src
OBJ = obj
LRES=res
CC = g++
PREFIX = /usr/local
RES = /usr/local/share/
LDFLAGS = -lXi -lXrandr -lXxf86vm -lX11 -lpthread -lglfw3 -lGL -lGLEW -lGLU -lfreeimage
CFLAGS = --std=c++11 -Wall -O2
INC = -Iinc

_OBJS = main.o game.o window.o shader.o vertex.o buffer.o vao.o texture.o mino.o text.o tetris.o
OBJS = $(patsubst %,$(OBJ)/%,$(_OBJS))

$(OBJ)/%.o: $(SRC)/%.cpp
	@$(CC) -c $(INC) -o $@ $< $(CFLAGS)

all: options obj ${NAME}

obj:
	@mkdir -p $(OBJ)

options:
	@echo "${NAME} build options:"
	@echo "CC= ${CC}"
	@echo "LDFLAGS: ${LDFLAGS}"

object: $(OBJS)

${NAME}: $(OBJS) 
	@echo CC -o $@
	@${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

clean:
	@rm -f ${OBJ}/*.o ${NAME}

install: all
	@echo installing to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${RES}/${NAME}
	@cp -fv ${NAME} ${DESTDIR}${PREFIX}/bin
	@cp -vR ${LRES}/* ${RES}/${NAME}
	@chmod 755 ${DESTDIR}${PREFIX}/bin/${NAME}

dist: all
	@mkdir -p ${NAME}-${VERSION}
	@cp -Rv res ${NAME}-${VERSION}
	@cp -v ${NAME} ${NAME}-${VERSION}
	@tar cf ${NAME}-${VERSION}.tar ${NAME}-${VERSION}
	@bzip2 ${NAME}-${VERSION}.tar
	@rm -rf ${NAME}-${VERSION}

gzip: all
	@mkdir -p ${NAME}-${VERSION}
	@cp -Rv res ${NAME}-${VERSION}
	@cp -v ${NAME} ${NAME}-${VERSION}
	@tar cf ${NAME}-${VERSION}.tar ${NAME}-${VERSION}
	@gzip ${NAME}-${VERSION}.tar
	@rm -rf ${NAME}-${VERSION}

uninstall:
	@echo removing from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/${NAME}
