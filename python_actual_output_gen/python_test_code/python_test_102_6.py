n , m = map(int, input().split())
mn = 10**10
for i in range(m):
    b, e = map(int, input().split())
    if e - b < mn:
        mn = e - b + 2
print(mn - 1)
for i in range(n):
    print (i % (mn-1), end = " ")