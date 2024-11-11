n = int(input())
A = [0] * n

for i in range(n):
    A[i] = tuple(map(int, input().split()))

A.sort(key = lambda x: x[1])
now, res = 0, 0

for i in range(n):
    if A[i][1] > now:
        now = A[i][0]
        res += 1
      
print(res)