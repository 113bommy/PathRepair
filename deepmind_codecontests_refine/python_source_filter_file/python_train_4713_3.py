def stringi(L):
    r=''
    for l in L:
        r+=str(l)
    return r

def construct(w,x):
    n = len(w)
    S=[0]*n
    for i in range(n):
        if i>=x:
            if w[i-x]=='1':
                S[i]='1'
        elif i+x<n:
            if w[i+x]=='1':
                S[i]='1'
    S=stringi(S)
    return S


T = int(input())
for i in range(T):
    s = input()
    x = int(input())
    n= len(s)
    w=[0]*n
    for i in range(n):
        if i>=x and i+x<n:
            if s[i-x]==s[i+x]=='1':
                w[i]='1'
        elif i>=x:
            if s[i-x]=='1':
                w[i]='1'
        elif i+x<n:
            if s[i+x]=='1':
                w[i]='1'
    w=stringi(w)
    S = construct(w,x)
    if S!=s:
        print(-1)
    else:
        print(w)
