n,p=list(map(int,input().split()))
s=list(input())
f=0
for i in range(n-p):
    if s[i]=='.':
        if s[i+p]=='.':
            s[i]='1'
            s[i+p]='0'
        else:
            s[i]='0' if s[i+p]=='1' else '1'
    else:
        if s[i+p]=='.':
            s[i+p]='0' if s[i]=='1' else '1'
for i in range(n):
    if s[i]=='.':
        s[i]='1'
for i in range(n-p):
    if s[i+p]!=s[i]:
        f=1
        break
if f:
    print('No')
else:
    print(''.join(s))