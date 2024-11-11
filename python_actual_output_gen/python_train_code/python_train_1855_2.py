p,n=map(int,input().split())
a=[]
p=[]
for i in range(n):
    p.append(int(input()))
j=1
for i in p:
    k=i%10
    if k in a:
        print(j)
        break
    else:
        a.append(k)
    j=j+1
else:
    print(-1)