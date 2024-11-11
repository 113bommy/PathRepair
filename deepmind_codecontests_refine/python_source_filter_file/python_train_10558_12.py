def checkG(g):
    return g%2==0


x=input()
g=input()
n=len(g)

l=x.find('|')
r=len(x)-x.find('|')-1

if r==l:
    if checkG(n):
        print(x[:l]+g[:int(n/2)]+'|'+x[l+1:]+g[int(n/2):])
    else:
        print("Impossible")
else:
    d=abs(r-l)
    if n<d:
        print("Impossible")
        exit()
    if checkG(n-abs(l-r)):
        if l<r:
            print(x[:l]+g[:d+int(n/2)]+'|'+x[l+1:]+g[d+int(n/2):])
        else:
            print(x[:l]+g[:int((n-d)/2)]+'|'+x[l+1:]+g[int((n-d)/2):])
    else:
        print("Impossible")
        
    
