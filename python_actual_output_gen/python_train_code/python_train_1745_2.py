n,k=map(int,input().split())
l=[]
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        l.append(i)
        if i*i!=n:
            l.append(n//i)
l.sort()
if k<len(l): print(l[k-1])
else: print(-1)
