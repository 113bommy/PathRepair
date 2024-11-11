from sys import stdin
s=stdin.readline().strip()
x=-1
ans=0
for i in range(len(s)):
    for j in range(1,4):
        if (i-2*j)>=0 and s[i]==s[i-j] and s[i-j]==s[i-2*j]:
            if (i-2*j)>x:
                ans+=(i-2*j-x)*(len(s)-i)
                x=i-2*j
print(ans)
