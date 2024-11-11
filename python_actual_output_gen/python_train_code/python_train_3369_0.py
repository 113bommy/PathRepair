while 1:
    n=int(input())
    if n==0:break
    a=list(map(int,input().split()))
    s=list(input())
    for i in range(len(s)):
        for j in range(a[i%n]):
            if s[i]=='A':s[i]='a'
            elif s[i]=='a':s[i]='Z'
            else:s[i]=s[i]=chr(ord(s[i])-1)
    print(*s,sep='')