n=int(input())
A1=[int(i) for i in input().split()]
A2=[int(i) for i in input().split()]
s=0
for i in range(1,n):
  t=sum(A1[:i])+sum(A2[i-1:])
  s=max(s,t)
print(s)