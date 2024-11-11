N = int(input())
L = [int(input()) for _ in range(5)]

m = min(L)
print(4 + (N+m-1)//m)
