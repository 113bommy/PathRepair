N = int(input())
A = list(map(int, input().split()))

A = sorted([a - i for a, i in enumerate(A)])

print(sum(abs(x-y) for x,y in zip(A, A[::-1]))/2)