n = int(input())
a = [int(input()) for i in range(n)]

for i in range(n):
    if i % 2 == 1:
        print("first")
        exit()
print("second")