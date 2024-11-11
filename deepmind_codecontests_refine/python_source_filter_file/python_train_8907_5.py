import math
a,b=input().split()
a,b=[int(a),int(b)]
n=int(input())
g=math.gcd(a,b)
ar=[]
i=1
while i*i<=g:
    if g%i==0:
        ar.append(i)
        ar.append(g/i)
    i+=1
ar.sort(reverse=True)
for i in range(0,n):
    c,d=input().split()
    c,d=[int(c),int(d)]
    i=0
    flag=0
    while i<len(ar):
        if ar[i]>=c and ar[i]<=d:
            flag=1
            break
        i+=1
    if flag==1:
        print(ar[i])
    else:
        print("-1")