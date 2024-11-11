n,m,w=map(int,input().split())
l=list(map(int,input().split()))
k=[]
for i in range(1,n):
       a=l[i]-l[i-1]
       k.append(a)
k.sort()
print(k)
s=0
for i in range(n-w):
    s+=k[i]
print(s+w)
