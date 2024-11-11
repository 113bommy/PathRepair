A,B=map(int,input().split())
n=0
for i in range(A,B):
  C=(str(i)[-1::-1])
  if int(C)==i:
    n=n+1
print(n)