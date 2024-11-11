from sys import stdin
test_cases=True

if test_cases:
    t=int(stdin.readline())
    while t:
        ans=1
        s=input()
        s='s'+s+'s'
        s=list(s)
        for i in range(1,len(s)-1):
            if s[i]=='?':
                if s[i-1]=='a':
                    if s[i+1]!='b':
                        s[i]='b'
                    elif s[i+1]!='c':
                        s[i]='c'
                        
                elif s[i-1]=='b':
                    if s[i+1]!='a':
                        s[i]='a'
                    elif s[i+1]!='c':
                        s[i]='c'
                else:
                    if s[i+1]!='a':
                        s[i]='1'
                    elif s[i+1]!='b':
                        s[i]='b'
            else:
                if s[i-1]==s[i] or s[i]==s[i+1]:
                    ans=-1
                    break
        s=''.join(s[1:-1])
        print(s if ans==1 else -1)
                
        t-=1
else:
    k,n=map(int,stdin.readline().split())