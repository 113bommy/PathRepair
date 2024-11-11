entrada = int(input(""))
hora = input("")
hora = hora.split(":")

if(entrada == 12):
	if(int(hora[0][0]) > 1):
		if(int(hora[0][1]) == 0):
			hora[0] = "10"
		else :
			hora[0] = "0" + hora[0][1]
	
	elif(int(hora[0][0]) == 0):
		if(hora[0][1] == 0):
			hora[0] = "01"
	
	elif(int(hora[0][0]) == 1):
		if(int(hora[0][1]) > 2):
			hora[0] = "0" + hora[0][1]
		
elif(entrada == 24):
	if(int(hora[0][0]) > 2):
			hora[0] = "0" + hora[0][1]
	
	elif(int(hora[0][0]) == 2):
		if(int(hora[0][1]) >= 4):
			hora[0] = "1" + hora[0][1]
	
	
if(int(hora[1][0]) > 5):
	hora[1] = "3" + hora[1][1]

print (hora[0] + ":" + hora[1])	