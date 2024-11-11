n=int(input())
for i in range(n):
  a,b=[int(num) for num in input().split()]
  print((abs(a-b)+9//10)%1000000007)
