n=int(input())
l=list(map(int,input().split()))
n=len(l)
k=[0]*n
for i in range(n):
    k[i]=(l[i]-i)//n
    if (l[i]-i)%n != 0:
        k[i]=k[i]+1
print(k)
print(k.index(min(k))+1)