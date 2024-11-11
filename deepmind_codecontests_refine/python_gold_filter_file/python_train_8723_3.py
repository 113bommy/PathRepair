n=int(input())
a=[int(i) for i in input().split()]
b=sum(a)//2
c=[0]*n
c[-1]=b-sum(a[:-1:2])
for i in range(n-1,0,-1):
  c[i-1]=a[i-1]-c[i]
print(" ".join([str(i*2) for i in c]))