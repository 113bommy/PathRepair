k=int(input())
s=list(input())
n=len(s)
ali=0;
for i in range(n):
    if s[i]==s[n-i-1]: ali+=1;
    elif s[i]=='?': s[i]=s[n-i-1]
    elif s[n-i-1]=='?': s[n-i-1]=s[i]
    else:
        print('IMPOSSIBLE')
        exit()
d=set(chr(i+97) for i in range(k) if chr(i+97) not in s)
for i in range(0,n//2+1,1):
    if s[i]==s[n-i-1]=='?':
        if len(d):
            s[i]=s[n-i-1]=min(d)
            d.remove(min(d))
        else:
            s[i]=s[n-i-1]='a'
if d:
    print('IMPOSSIBLE')
else:
    print(*s,sep='')