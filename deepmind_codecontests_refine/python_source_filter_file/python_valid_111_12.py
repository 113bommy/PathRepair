casos=int(input())
cont=0
while cont!=casos:
    cont+=1
    n=int(input())
    if n==1:
        print('()')
    elif n==2:
        print('()()')
        print('(())')
    else:
        cont2=2
        print(("("*n)+(')'*n))
        print('()'*(2*n))

        for i in range (2,n):
            cadena=('('*i)+(')'*i+('()'*(n-i)))
            cadena2=(('()'*(n-i))+'('*i)+(')'*i)
            if cont2!=n:
                print(cadena)
                cont2+=1
                if cont2!=n:
                    print(cadena2)
                    cont2+=1
            if cont2==n:
                break
            
            
            