s = input()
k = int(input())
l = {}
distinct = 0
for i in range(len(s)):
    if ord(s[i])-97 not in l: distinct += 1; l[ord(s[i])-97] = 0
    l[ord(s[i])-97] += 1
    
d = sorted([[l[i],i] for i in l.keys()])

for i in range(distinct):
    if k>0:
        k -= d[i][0]
        if k >= 0: distinct -= 1; d[i][0] = 0; l[d[i][1]] = 0
        else:break
    else:break

print(max(distinct,0))
if distinct > 0:
    for i in range(len(s)):
        if l[ord(s[i])-97]: print(s[i],end="")
        
else:
    print()