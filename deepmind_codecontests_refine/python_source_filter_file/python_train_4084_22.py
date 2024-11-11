n=int(input())
num=input().split()
for i in range (n):
    num[i]=int(num[i])
finals=[]
l=[0]*n
for i in range(65,0,-1):
    t=0
    k=0
    for j in range(n):
        a=num[j]
        if (a>>i)%2==1 and l[j]!=1:
            k=j
            t+=1

    if (t==1):
        finals.append(num[k])
        l[k]=1
for i in range(n):
    if l[i]!=1:
        finals.append(num[i])
for i in range (n):
    print (finals[i],end=' ')

    
