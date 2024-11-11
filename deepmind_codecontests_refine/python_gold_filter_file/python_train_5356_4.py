p,n=map(int,input().split())
a=[]
b=[]
for i in range(n):
    b.append(int(input()))
j=1
for i in b:
    r=i%p
    if r in a:
        print(j)
        break
    else:
        a.append(r)
    j=j+1
else:
    print(-1)
