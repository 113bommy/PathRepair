n, a = map(int, input().split())

t = list(map(int, input().split()))
b = sum(t)
l = a - 1
r = a + 1
while l >= 0 and r < n:
    b -= (t[l] + t[r]) % 2
    l -= 1
    r += 1
print(b)