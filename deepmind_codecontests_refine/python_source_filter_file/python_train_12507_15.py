n = int(input())
tmp = []
for i in range(n):
  tmp.append([int(x) for x in input().split(' ')])
k = int(input())
for i in range(n):
  if tmp[i][0] < k <= tmp[i][1]:
    print(n - i)
