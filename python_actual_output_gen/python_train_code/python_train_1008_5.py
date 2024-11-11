n = int(input())
a = list(input().split())

if not n % 2:
    a.insert(n//2, '0')
    n += 1

for i in range(n):
    if i % 2 and a[i] != '0':
        print(a[i], end=' ')
    elif a[i] != '0':
        print(a[n-1-i], end=' ')
