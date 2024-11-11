t=int(input())

for i in range(0,t):

    x,y,z=[int(x) for x in input().split()]
    l=[]
    l.append(x)
    l.append(y)
    l=sorted(l)
    ans=0
    j=0
    while(ans<=z):
       ans=l[-1]+l[-2]
       l.append(ans)
       j+=1
    print(j)
    print(l)
    
