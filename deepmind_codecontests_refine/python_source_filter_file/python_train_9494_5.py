t=int(input())
for _ in range(t):
    n=int(input())
    a,b,c=map(int,input().split())
    s=input()
    ro=s.count('R')
    pa=s.count('P')
    si=s.count('S')
    k1=min(a,si)+min(b,ro)+min(c,pa)
    if(k1>n//2):
        print("YES")
        q=[0]*n
        for i in range(0,n):
            if(s[i]=='R' and b!=0):
                q[i]='P'
                b-=1
            elif(s[i]=='P' and c!=0):
                q[i]='S'
                c-=1
            elif(s[i]=='S' and a!=0):
                q[i]='R'
                a-=1
        for i in range(0,n):
            if(q[i]==0 and b!=0):
                q[i]='P'
                b-=1
            elif(q[i]==0 and c!=0):
                q[i]='S'
                c-=1
            elif(q[i]==0 and a!=0):
                q[i]='R'
                a-=1
        print(''.join(map(str,q)))
    else:
        print("NO")
