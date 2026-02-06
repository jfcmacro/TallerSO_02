.phony: clean

all: error obtener_error

error: error.c
	${CC} -o $@ $<

obtener_error: obtener_error.c
	${CC} -o $@ $<

clean:
	rm -f error obtener_error
	rm -f *~
