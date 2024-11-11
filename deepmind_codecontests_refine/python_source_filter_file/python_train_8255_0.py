for _ in range(int(input())):
    n=int(input())
    s=input()
    for i in range(n):
        for j in range(i+1,n):
            if (s[j-1]!=s[i]) and (s[j]==s[i]):
                f=1
                break
        if f==1:
            break
    if f==0:
        print('yes')
    if f==1:
        print('no')