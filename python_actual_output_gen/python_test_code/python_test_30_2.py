n = int(input())
f1 = 1
f2 = 1
ans = 0
while f2 < n:
    f1, f2 = f2, f1+f2
    ans += 1
print(ans)