n = input()
s = input()

ans = 0
count = 0

for i in s:
    if i == 'w':
        count += 1
    elif count:
        count -= 1
        ans += 1
    else:
        pass


print(ans)
