n = int(input())
a = [int(input()) for _ in range(n)]

for i in range(n):
    if a[i] % 2 == 1:
        print("first")
        exit()

print("second")
