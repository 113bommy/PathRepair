def mensaje(direccion,tex):
    mensaje=[]
    teclado1="qwertyuiop"
    teclado2="asdfghjkl;"
    teclado3="zxcvbnm,."
    if (direccion=="R" or direccion=="r"):
            for i in tex:
                if i=="p" or i==";" or i==".":
                    mensaje.append(i)
                else:
                    flag=0
                    while flag==0:
                        for j in range (len(teclado1)):
                            if i==teclado1[j]:
                                mensaje.append(teclado1[j-1])
                                flag=flag+1
                        for k in range (len(teclado2)):
                            if i==teclado2[k]:
                                mensaje.append(teclado2[k-1])
                                flag=flag+1
                        for h in range (len(teclado3)):
                            if i==teclado3[h]:
                                mensaje.append(teclado3[h-1])
                                flag=flag+1
    if (direccion=="L" or direccion=="l"):
            for i in tex:
                if i=="q" or i=="a" or i=="z":
                    mensaje.append(i)
                else:
                    flag=0
                    while flag==0:
                        for j in range (len(teclado1)):
                            if i==teclado1[j]:
                                mensaje.append(teclado1[j+1])
                                flag=flag+1
                        for k in range (len(teclado2)):
                            if i==teclado2[k]:
                                mensaje.append(teclado2[k+1])
                                flag=flag+1
                        for h in range (len(teclado3)):
                            if i==teclado3[h]:
                                mensaje.append(teclado3[h+1])
                                flag=flag+1
    return (mensaje)
def main():
    direccion=(input())
    tex=(input())
    mensaje1=mensaje(direccion,tex)
    for i in range(len(mensaje1)):
        print(mensaje1[i],end="")
main()
