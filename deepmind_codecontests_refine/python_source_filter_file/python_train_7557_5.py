l=list(input())
s=list(input())
n=int(input())
ans=[]
les=len(s)
if not ('*' in s):
    for _ in range(n):
        x=list(input())
        lex=len(x)
        if les!=lex:
            ans+=['NO']
        else:
            for i in range(les):
                if s[i]=='?':
                    if x[i] in l:
                        continue
                    else:
                        ans+=["NO"]
                        break
                elif s[i]==x[i]: continue
                else: ans+=["NO"]; break
            else: ans+=["YES"]
else:
    s0,s1=s[:s.index("*")],s[s.index("*")+1:]
    s1=s1[::-1]
    les0,les1=len(s0),len(s1)
    for _ in range(n):
        x=list(input())
        lex=len(x)
        if les0+les1>lex: ans+=['NO']
        else:
            for i in range(les0):
                if s0[i]=='?':
                    if x[i] in l:
                        continue
                    else:
                        ans+=["NO"]
                        break
                elif s0[i]==x[i]: continue
                else: ans+=["NO"]; break
            else:
                for i in range(les1):
                    if s1[i]=='?':
                        if x[-1-i] in l:
                            continue
                        else: ans+=["NO"]; break
                    elif s1[i]==x[-1-i]: continue
                    else: ans+=["NO"]
                else:
                    for i in range(les0,lex-les1):
                        if x[i] in l: ans+=["NO"]; break
                    else: ans+=["YES"]
print('\n'.join(ans))