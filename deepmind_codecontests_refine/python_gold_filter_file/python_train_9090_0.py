n=int(input())
pr,cnt=0,1
E=0
for i in range(n):
    s=input().split()
    a,b=int(s[0][1:3]),int(s[0][4:6])
    e='p' in s[1]
    a%=12
    t=60*a+b+12*60*e
    if(t==pr):
        E+=1
        if(E>10):
            cnt+=1
            E=1
    else:
        E=1
    if(t<pr):
        cnt+=1
    pr=t
    #print(a,b,e,t)
print(cnt)
