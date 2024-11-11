n = input().split()
contador = 0
numero = 0
a = 0
while numero < int(n[1]):
    numero = int(n[2])**contador  
    contador += 1
    if numero < int(n[1]) and numero >= int(n[0]):
         print(numero, end=" ")
         a += 1
if a == 0:
    print("-1")     
                                  
    
