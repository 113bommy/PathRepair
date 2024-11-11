str = input()
x = 0
ans = 0
for i in str:
    if i == '(':
        x += 1
        ans += 1
    elif x > 0:
        x-=1
        ans += 1
print(ans)