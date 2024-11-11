s=input()
n=int(input())
a=int(0)
b=int(0)
for i in range(len(s)):
    if s[i]=='?':
        a+=1
    elif s[i]=='*':
        b+=1
if len(s)-a-b==n:
    for i in range (len(s)):
        if s[i]!='*' and s[i]!='?':
            print(s[i], end='')
elif len(s)-a-b<n:
    if b>0:
        c=n-len(s)+1+a+b
        x=s.index('*')
        q=(s[0:x-1]+s[x-1]*c+s[x+1:len(s)])
        for i in range(len(q)):
            if q[i] != '*' and q[i] != '?':
                print(q[i], end='')
    else:
        print('Impossible')
else:
    if len(s)-n-a-b>a+b:
        print('Impossible')
    else:
        z=len(s)-n-a-b
        while a>0 and z>0:
            f=s.index('?')
            a-=1
            z-=1
            if f<len(s):
                s=s[0:f-1]+s[(f+1):]
            else:
                s=s[0:f-1]

        while b>0 and z>0:
            z-=1
            b-=1
            f=s.index('*')
            if f<len(s):
                s=s[0:f-1]+s[(f+1):]
            else:
                s=s[0:f-1]

        for i in range(len(s)):
            if s[i] != '*' and s[i] != '?':
                print(s[i], end='')