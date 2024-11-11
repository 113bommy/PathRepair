n = int(input())
A = [int(input()) for i in range(n)]

print(sum(A) - max(A) // 2)