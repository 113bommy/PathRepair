N = int(input())
A = list(map(int, input().split()))
n = sum(A) // N
A2 = [abs(n - a) for a in A]
min_a = min(A2)
print(A2.index(min_a))
