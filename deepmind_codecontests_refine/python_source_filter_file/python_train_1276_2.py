LETRAS = "abcdefghijklmnopqrstuvwxyz"

def string_boa(indice, string):
    letras = LETRAS[indice]
    
    if len(string) == 1:
        if string != letras:
            return 1
        else:
            return 0
    
    direita = 0
    esquerda = 0
    
    for l in string[:len(string)//2]:
        if l != letras:
            direita += 1

    for l in string[len(string)//2:]:
        if l != letras:
            esquerda += 1

    lado_direito = direita + string_boa(indice - 1, string[len(string)//2:]) 
    lado_esquerdo = esquerda + string_boa(indice + 1, string[:len(string)//2:])
   
    return min(lado_direito , lado_esquerdo)
                
        
        
 
 
entrada = int(input())

for i in range(entrada):
    n = int(input())
    string = input()
    print(string_boa(0, string))