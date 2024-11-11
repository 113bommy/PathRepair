N=int(input())
A=list(map(int,input().split()))
x=0
for i in A:
  x+=1/i
print(1/x)
