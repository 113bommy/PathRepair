s=list(input())
cnt=0
now=''
for i in range(len(s)):
    now+=s[i]
    if buf!=now:
        buf=now
        now=''
        cnt+=1
print(cnt)
