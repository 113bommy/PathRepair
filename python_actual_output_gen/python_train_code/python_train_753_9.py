n = int(input())
a = list(map(int,input().split()))
k = 1
for k in a:
  if k%2 == 0:
    k *= 2
print(3**n-k)