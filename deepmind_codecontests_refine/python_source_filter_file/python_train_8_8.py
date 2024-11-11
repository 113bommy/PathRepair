def main():
	cant = int(input(""))
	numero= input("")
	wordlist = list(numero)
	posible = cant // 11
	cont8=0
	for x in range (len(wordlist)-1):
		letra = wordlist[x]
		if  letra == "8":
			cont8+=1
	if cont8==0:
		print("0")
		return
	elif cont8 >= posible:
		print (posible)
		return
	elif cont8 < posible:
		print (cont8)
		return


main()