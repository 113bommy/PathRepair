n,*o=open(0)
n=int(n)
r=list(range(n))
print(sum((n-a-b)*all(o[(i+b)%n][(a+j)%n]==o[(j+b)%n][(a+i)%n]for i in r for j in r)for a,b in zip(r+[0]*n,[0]*~-n+r)))