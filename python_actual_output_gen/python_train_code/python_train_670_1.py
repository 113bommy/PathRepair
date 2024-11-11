n=int(input())
a=[0]*n
b=[0]*n
for i in range(n*(n-1)//2-1):
    c,d=list(map(int,input().split()))
    a[c-1]+=1
    b[c-1]+=1
    b[d-1]+=1
f=-1
g=-1
for i in range(n):
    if b[i]==n-2:
        if f==-1:
            f=i+1
        else:
            g=i+1
            break
if b[f-1]>b[g-1]:
    print(f,g)
else:
    print(g,f)