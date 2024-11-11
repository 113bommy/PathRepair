n=int(input())
a,b=[],0
for i in range(n):
  p,q=map(int,input().split())
  a+=[p+q]
  b-=q
print(sum(sorted(a)[::2])+b)