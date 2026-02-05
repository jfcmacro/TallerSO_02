all: error obtener_error recuperar_error

error: error.c
	${CC} -o $@ $<

obtener_error: obtener_error.c
	${CC} -o $@ $<

recuperar_error: recuperar_error.c
	${CC} -o $@ $<

clean:
	rm -f error recuperar_error
	rm -f *~
