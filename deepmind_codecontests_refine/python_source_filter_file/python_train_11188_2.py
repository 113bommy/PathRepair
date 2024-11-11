


numero = int(input())
requests = []
for x in range(numero):
	requests.append(input().split(" "))
class nombre():
	"""docstring for nombre"""
	def __init__(self, actual, hijo, parent):
		self.actual = actual
		self.hijo = hijo
		self.parent = parent

def buscar_segun_string(lista_objetos, string):
	for obj in lista_objetos:
		if obj.actual == string:
			return obj

dic = {}
grafo = {}
lista_nombres = list()
lista_pares = list()
pares = []
#print(requests)
#for req in requests:
#	#a0 = nombre(req[0], None, nombre(req[1], ))
#	lista_nombres.append(nombre(req[0], None, None))
#	lista_nombres.append(nombre(req[1], None, None))


for nombre in lista_nombres:
	for nombre1 in lista_nombres:
		if nombre != nombre1 and nombre1.actual == nombre.actual:
			lista_nombres.remove(nombre1)

lista_si_existe = [None for x in range(2*numero)]


contador = 0
for req in requests:
	existe = False
	for i in range(2*numero):
		if lista_si_existe[i] == None:
			continue
		#if lista_si_existe[i] != None:
			#print("req 0, lista[i]", req[0], lista_si_existe[i].actual)
		elif lista_si_existe[i] != None and req[0] == lista_si_existe[i].actual:
			aux1 = nombre(req[1],None,None)
			#print("aux1: ", aux1.actual)
			lista_si_existe[i].hijo = aux1
			aux1.parent = lista_si_existe[i]
			lista_si_existe[contador] = aux1
			existe  = True
			contador += 1
			break
	if not existe:
		aux1 = nombre(req[0],None,None)
		aux2 = nombre(req[1],None,None)
		aux1.hijo = aux2
		aux2.parent = aux1
		lista_si_existe[contador] = aux1
		lista_si_existe[contador + 1] = aux2
		contador += 2

print(lista_si_existe[0].hijo.hijo.actual)
##
# for req in requests:
# 	#a0 = nombre(req[0], None, nombre(req[1], ))
# 	lista_pares.append([nombre(req[0], None, None),nombre(req[1], None, None)])
# 	#lista_nombres.append()
# aux = []
# for req in requests:
# 	llegada = buscar_segun_string(lista_nombres, req[1])
# 	inicio = buscar_segun_string(lista_nombres, req[0])
# 	inicio.hijo = llegada
# 	llegada.parent = inicio
# 	aux.append([inicio,llegada])
# 	#print("hola: ", llegada.actual)


# respuesta = []
# for par in aux:
# 	#print("par:", par[0].actual)
# 	if par[0].parent == None: #significa que es papa y no tiene padre (old)
# 		aux3 = par.copy()
# 		aux2 = par
# 		aux = par
# 		while aux[0].hijo != None:
# 			aux[0] = aux[0].hijo

# 		respuesta.append([aux3[0].actual,aux[0].actual])
respuesta = []
for nombre in lista_si_existe:
	if nombre != None and nombre.parent == None:
		copia = nombre
		while nombre.hijo != None:
			nombre = nombre.hijo
		respuesta.append([copia.actual,nombre.actual])

# for user in lista_nombres:
# 	if user.parent == None: #significa que es papa y no tiene padre (old)

# 		aux = user
# 		while aux.hijo != None:
# 			aux = aux.hijo
# 		respuesta.append([user.actual,aux.actual])

print(len(respuesta))
for item in respuesta:
	print("{} {}".format(item[0],item[1]))
