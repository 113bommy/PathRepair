n, k = map(int, input().split())

i = 1
while k ** i < n:
    i += 1
print(i)