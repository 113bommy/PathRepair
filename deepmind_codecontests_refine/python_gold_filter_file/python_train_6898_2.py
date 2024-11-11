import re
t=int(input())
for i in range(t):
    s=input()
    y=re.findall('1+',s)
    for i in y:
        i=int(i)
    y.sort()
    i=len(y)-1
    ans=0
    while(i>=0):
        ans=ans+len(y[i])
        i-=2
    print(ans)
    
    
    