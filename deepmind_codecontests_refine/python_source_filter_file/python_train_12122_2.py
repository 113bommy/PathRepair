n = [int(x) for x in input().split()]
p = [int(x) for x in input().split()]
maxx =p[0]
for i in range(1,n[1]):
    print("maxx ="+str(maxx))
    if(p[i]>maxx): p[i] = -1
    else: maxx = p[i]
#print(p)
p.sort()
j = 0
while(p[j]==-1): j+=1
for i in range(1,n[0]+1):
    if(j+1!= n[1] and i==p[j+1]): 
        j+=1
    print(p[j],end = " ")
    