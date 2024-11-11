import sys
t=int(input().strip())
for a0 in range(t):
    n=int(input())
    s=input()
    if(s.count('1')==0):
        print(n)
    elif(s.count('1')==1):
        a=1
        for i in s:
            if(i=='1'):
                break
            else:
                a+=1
        print(max(2*a,2*(n-a+1)))
    elif(s[0]=='1' or s[len(s)-1]=='1'):
        print(2*n)
    else:
        m=s[::-1]
        a=0
        for i in s:
            if(i=='1'):
                break
            else:
                a+=1
        b=n-1
        for i in m:
            if(i=='1'):
                break
            else:
                b-=1
        x=s[0:a+1]
        y=s[b::]
        t=max(x.count('0'),y.count('0'))
        print(2*(b-a+1)+t)
        
        
    