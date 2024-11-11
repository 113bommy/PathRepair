k,n=map(int,input().split())
l=list(map(int,input().split()))
l.append(l[0]+k)
a=10**10
for i in range(n):
    a=min(a,l[i+1]-l[i])
print(k-a)