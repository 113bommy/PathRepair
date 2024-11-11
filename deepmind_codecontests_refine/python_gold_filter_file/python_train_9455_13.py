N = int(input())
A = list(map(int, input().split()))
A.sort()

n = A.pop()
A.sort(key=lambda a: abs(a - n / 2))
r = A[0]
print(n, r)
