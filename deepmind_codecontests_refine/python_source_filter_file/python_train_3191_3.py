n=int(input())
a=[]
for _ in range(n):
    s=list(map(int,input().split(":")))
    a.append(s[0]*60+s[1])
if n==1:
    print("23:59")
else:
    
    b=[]
    for i in a:
        b.append(23*60+59+i)
    a=a+b
    a.sort()
    mx=0
    for i in range(1,len(a)):
        mx=max(mx,a[i]-a[i-1])
    mx-=1
    s=""
    h=str(mx//60)
    if len(h)==1:
        h="0"+h
    m=str(mx%60)
    if len(m)==1:
        m="0"+m
    s=h+":"+m
    print(s)
    

    