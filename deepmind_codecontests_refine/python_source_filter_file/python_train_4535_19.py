

n = int(input())

A = sorted([int(x) for x in input().split()])

print(A[len(A) // 2 - 1])
