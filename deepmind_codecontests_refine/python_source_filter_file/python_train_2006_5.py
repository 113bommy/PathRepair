
t = int(input())
for i in range(0,t):
  n,k = map(int, input().split(" "))
  if k > n:
    print(k-n)
  else:
    print(0)
