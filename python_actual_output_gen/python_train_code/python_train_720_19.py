n=int(input())
def f(x):
  x=int(x)
  cnt=0
  while x%2==0:
    cnt+=1
    x=x//2
  return cnt
a=list(map(f,input().split()))
print(max(a))