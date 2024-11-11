t=int(input())
for i in range(0,t):
    n=int(input())
    s=input()
    s1=''.join(sorted(s))
    print(s)
    print(s1)
    c=0
    for j in range(0,n):
        if(s[j]!=s1[j]):
            c=c+1
    print(c)