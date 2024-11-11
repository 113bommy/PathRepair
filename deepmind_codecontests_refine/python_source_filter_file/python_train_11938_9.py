n,p=map(int,input().split())
s=list(input())
made_no_p=0 
for i in range(n//2):
    if s[i]=='.':
        if i+p<n :
            if s[i+p]=='.':
                s[i]='1'
                s[i+p]='0'
                made_no_p=1 
            elif s[i+p]=='0':
                s[i]='1'
                made_no_p=1 
            elif s[i+p]=='1':
                s[i]='0'
                made_no_p=1 
    if i+p<n:
        if s[i+p]=='.':
            if s[i]=='0': 
                s[i+p]='1'
                made_no_p=1 
            if s[i]=='1':
                s[i+p]='0'
                made_no_p=1 
        if s[i]!=s[i+p]:
            made_no_p=1 
if made_no_p:
    for i in range(n):
        if s[i]=='.':
            s[i]='1'
    print(''.join(s))
else:
    print('No')