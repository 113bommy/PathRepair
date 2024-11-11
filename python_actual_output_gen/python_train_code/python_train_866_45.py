a=int(input())
b=int(input())
c=int(input())



while(a>0):
    if(a*2<=b and a*4<=c):
        print(a+(2*a)+(4*a))
        break

    a-=1
print(0)