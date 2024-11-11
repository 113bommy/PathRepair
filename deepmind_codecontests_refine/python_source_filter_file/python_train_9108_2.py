n=int(input())
ip1=[]
ip2=[]
for i in range(n):
    a,b=map(int,input().split())
    ip1.append(a)
    ip2.append(b)
if n<=1:
    print(-1)
elif n>=3:
    ip1=sorted(ip1)
    ip2=sorted(ip2)
    print(abs(ip1[-1]-ip2[0])*abs(ip2[-1]-ip2[0]))
else:
    a,b=ip1[0],ip2[0]
    c,d=ip1[1],ip2[1]
    if a==c or b==d:
        print(-1)
    else:
        print(abs(c-a)*abs(d-b))
    
    
