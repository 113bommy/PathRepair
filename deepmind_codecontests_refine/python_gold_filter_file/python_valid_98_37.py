def f(n,s):
    for i in range(n-1):
        if s[i]!=s[i+1]:
            return i
    return -1

t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    res=f(n,s)
    if res==-1:
        print("-1 -1")
    else:
        print(res+1,res+2)    