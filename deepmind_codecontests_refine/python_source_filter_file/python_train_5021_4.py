n = int(input())
s = input()
cnt = 0
l = 0
ans = 0
cntl, cntr = 0, 0
for i in s:
    if i == '(':
        cnt -= 1
        cntl += 1
        if cnt < 0:
            ans += 1
    else:
        cnt += 1
        cntr += 1
        if cnt <= 0:
            ans += 1

print(ans if cntl == cntr else -1)
