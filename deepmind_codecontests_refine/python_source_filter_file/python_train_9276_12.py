n = int(input())
x = list(input().split()[1:])
x = set(x)
for i in range(n-1):
    y = list(input().split()[1:])
    y = set(y)
    x = x&y
for j in x:
    print(j, end='')
