a, b = input().split()
n = int(input())
for i in range(n):
    print(a, b)
    c, d = input().split()
    if b == c:
        b = d
    else:
        a = c
print(a, b)