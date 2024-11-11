a, b = input().split()
n = int(input())
for i in range(n):
    print(a, b)
    c, d = input().split()
    if a == c:
        a = d
    else:
        b = d
print(a, b)