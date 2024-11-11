N = int(input())
A = [int(i) for i in range(N)]

print(sum(A) - max(A) // 2)