x=int(input())
for i in range(x):
    y=int(input())
    d='()'*y
    z=list(d)
    print(d)
    for j in range (1,(len(z)//2)):
        if j%2!=0:
            z[j]='('
            z[-(j+1)]=')'
        else:
            z[j]=')'
            z[-(j+1)]='('
    print ("".join(z))            

    