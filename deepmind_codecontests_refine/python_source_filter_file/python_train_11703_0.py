a=int(input())
s=input()

di = {}
for i in range(len(s)):
    total=0
    for j in range(i, len(s)):
        total += int(s[j])
        di[total] = 1 if total not in di else di[total]+1

ans=0
if a==0:
    ans=0
    if 0 in di:
        ans +=di[0]
        for each in di:
            if not each:continue
            ans += di[each]*di[0]*2
    print(ans)
    quit()
for p in di:
    if p and a % p == 0 and (a//p) in di:
        ans += di[a//p]*di[p]
print(ans)