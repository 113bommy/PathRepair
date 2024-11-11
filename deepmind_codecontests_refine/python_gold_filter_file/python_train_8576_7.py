n=input()
m=int(n)
a=len(n)
p=int(m/10)
q=int(m/100)
c=0
if m>=0:
    print(n)
else:
    c=(abs(m))%10
    if ((q*10)-c)>p:
        print((q*10)-c)
    else:
        print(p)
    
