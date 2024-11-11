n=int(input())
L=list(map(int,input().split()))
O=[]
E=[]
for l in L:
    if(l%2==1):
        O.append(l)
    else:
        E.append(l)
if(abs(len(O)-len(E))==1):
    print(0)
elif(len(O)>len(E)):
    O.sort()
    print(sum(O[:len(O)-len(E)-1]))
else:
    E.sort()
    print(sum(E[:len(E)-len(O)-1]))
    
    
