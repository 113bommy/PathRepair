a = int(input())
b = int(input())
n = b+1
ans = str(n) + ' '
for i in range(a):
    n += 1
    ans += str(n) + ' '
n = b+1
for i in range(b):
    n -= 1
    ans += str(n) + ' '
print(ans)
