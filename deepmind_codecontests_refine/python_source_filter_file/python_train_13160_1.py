from operator import itemgetter
n = int(input())
a = list(map(int, input().split()))
b = sorted(enumerate(a), key=itemgetter(1))
for i in range(1, n):
  if b[i - 1][1] == b[i][1]:
    a[b[i][0]] = a[b[i - 1][0]] + 1
print(' '.join(map(str, a)))