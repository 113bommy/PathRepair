N = int(input())
A = [int(input()) for _ in range(N)]

print("second" if all(a[i] % 2 == 0 for i in range(N)) else "first")
