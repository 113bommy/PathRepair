n,x = map(int,input().split())
a=[]
for _ in [0]*n:
  a += [int(input())]
print(n+(n-sum(a))//min(a))