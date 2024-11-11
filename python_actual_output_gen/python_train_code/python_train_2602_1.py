n = int(input())
s = str(input())
s1 = ''
count = 0
for i in range(n):
    if s1.find(s[i]) < 0:
        s1 += s[i]
    else:
        count += 1
if count >= 26:
    print(-1)
else:
    print(count)