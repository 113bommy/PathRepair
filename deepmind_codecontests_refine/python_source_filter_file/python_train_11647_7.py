s = list(input())
ls = len(s)
for i in range(1, ls):
    if s[i] == s[i-1]:
        print(i, i+2)
        break
    if i == 1:
        continue
    if s[i] == s[i-2]:
        print(i-1, i+1)
        break
else:
    print(-1, -1)