largo = int(input(""))
binario = input("")

ceros = 0
unos = 0

for caracter in binario:
        if caracter == 0:
            ceros += 1
        else:
            unos += 1
           
good = False

if ceros != unos:
    good = True
    
if largo == 1 or good == True:
    print(largo)
    print(binario)
    
else:
    
    s1 = binario[0]
    s2 = binario[1:largo]
    
    ceros = 0
    unos = 0
    
    for caracter in s2:
        if caracter == 0:
            ceros += 1
        else:
            unos += 1
    
    if ceros == unos:
        s1 = binario[0] + binario[1]
        s2 = binario[2:largo]
    print(2)    
    print(s1 + " " + s2)