n = input()
ans = 0
for num in n:
    ans += int(num)
if ans == 1:
    ans = 10
print(ans)