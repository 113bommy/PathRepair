n,k=map(int,input().split())
a = list(map(int, input().strip().split(' ')))
a.sort()
b = [0]*(n+1)
c = [0]*(n+1)
h=int(0)
i=int(1)
u=int(0)
b[0]=1
n1=int(n)
if n==1:
    print(a[0],a[0])
    h=1
c[u]=a[0]
while(h==0):
    if a[i]==a[i-1]:
        b[u]+=1
        i+=1
    else:
        u+=1
        c[u]=a[i]

        i+=1

        b[u]+=1
    if i == n:
        break
i=int(0)
j=int(0)

while(h==0):
    if k>b[i]*n1:
        k-=b[i]*n1
        i+=1
    else:
        if k>b[i]*b[j]:
            k-=b[i]*b[j]
            j+=1
        else:
            print(a[i],a[j])
            break
