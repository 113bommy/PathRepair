n = int(input())
s = input()
x = ans = 0
for c in s:
    if c == x:
        x += 1
    else:
        ans += (x - 2) if x > 2 else 0
        x = 0
print(ans)
