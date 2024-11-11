K,N=map(int,input().split())
A=list(map(int,input().split()))
l=[]
p = A[-1]-K
for a in A:
  l.append(a-p)
  p=a
print(sum(l)-max(l))
