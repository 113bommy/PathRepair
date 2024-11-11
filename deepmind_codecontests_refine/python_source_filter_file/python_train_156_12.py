n, k = map(int, input().split(' '))
d = list(map(int, input().split(' ')))

sum = 0

for i in range(1, len(d)):
  sum += i
  if(sum >= k):
    sum = i-(sum-k)
    print(d[sum-1])
    break

