n=int(input())
for i in range(n):
    l=[]
    m=input()
    j=0
    while(j<len(m)-1):
        l.append(m[j ])
         
        j=j+2
    print (''.join(l)+m[-1])
