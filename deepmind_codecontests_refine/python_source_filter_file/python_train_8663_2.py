s=input()
One=[0]*26
Two=[[0]*26 for i in range(26)]
for i in range(len(s)):
    c=ord(s[i])-ord('a')

    for j in range(26):
        Two[j][c]+=One[c]
    One[c]+=1
ans=max(One)
for i in range(26):
    r=max(Two[i])
    if r>ans: ans=r
print(ans)