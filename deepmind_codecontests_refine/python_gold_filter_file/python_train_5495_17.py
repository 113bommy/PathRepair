k,n=map(int,input().split())
l=list(map(int,input().split()))
l.append(l[0]+k)
a=0
for i in range(n):
    a=max(a,l[i+1]-l[i])
print(k-a)
