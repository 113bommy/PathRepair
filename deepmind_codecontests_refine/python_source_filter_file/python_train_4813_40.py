import sys
import math
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if b%a==0 and c%b==0:
        print(0)
        print(a,b,c)
        continue
    ans=100000
    N=10001
    p=[]
    for i in range(a,N):
        t1=i-a
        y=i
        while(y<N):
            t2=abs(y-b)
            z=y
            q3=abs(z-c)
            while(z<N):
                t3=abs(z-c)
                if(t1+t2+t3<ans):
                    ans=t1+t2+t3
                    p=[i,y,z]
                if(t3>q3):
                    break
                q3=abs(z-c)
                z+=y
            y+=i
    for i in range(a,0,-1):
        t1=a-i
        y=i
        while(y<N):
            t2=abs(y-b)
            z=y
            q3=abs(z-c)
            while(z<N):
                t3=abs(z-c)
                if(t1+t2+t3<ans):
                    ans=t1+t2+t3
                    p=[i,y,z]
                if t3>q3:
                    break
                q3=abs(z-c)
                z+=y
            y+=i
    print(ans)
    print(*p)
