n = int(input())
s = 1
while n > 9:
    n -= max(map(int, str(n)))
    s += 1
print(s)
