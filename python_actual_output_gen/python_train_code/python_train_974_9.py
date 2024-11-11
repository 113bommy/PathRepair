n=int(input())
l=[int(i) for i in input().split()]
s=0
for i in range(n):
  for j in range(i,n):
    s+=j*i
print(s)