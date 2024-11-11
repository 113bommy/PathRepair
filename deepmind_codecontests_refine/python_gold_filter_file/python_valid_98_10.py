def balanced(n,s):
    for i in range(1,n):
        if s[i]!=s[i-1]:
            return (i,i+1)
    return (-1,-1)
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    ans=balanced(n,s)
    print(ans[0],ans[1])