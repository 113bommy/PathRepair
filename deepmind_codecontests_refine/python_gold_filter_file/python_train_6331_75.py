N = int(input())
A = [int(input()) for i in range(N)]
print(sum(A) - max(A)//2)