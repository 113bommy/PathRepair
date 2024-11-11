for u in range(int(input())):
    n,k=map(int,input().split())
    s=''.join(sorted(input()))
    if(k==n or s[0]!=s[k-1]):
        print(s[k-1])
    elif(s[0]==s[-1]):
        print(s[0]+s[k]*((n-1)//k))
    else:
        print(s[k-1:])