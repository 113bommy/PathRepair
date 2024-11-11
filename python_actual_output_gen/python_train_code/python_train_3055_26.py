n = int(input())
s = input()
tmp = s[0]
cnt = 0
for i in range(1, len(s)):
    if tmp == s[i]:
        cnt +=1
    tmpl = s[i]
print(cnt)