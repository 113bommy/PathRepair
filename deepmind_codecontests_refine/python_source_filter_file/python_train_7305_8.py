q = int(input().strip())

for i in range(q):
    n,a,b = [int(x) for x in input().strip().split()]
    r = [int(x) for x in input().strip()]
    i=0
    r2 =[]
    while i<n:
        if r[i]==0:
            r2.append([0,0])
            while i<n and r[i]==0:
                r2[-1][1]+=1
                i+=1
            #i-=1
        else:
            r2.append([1, 0])
            while i<n and r[i] == 1:
                r2[-1][1] += 1
                i += 1
            #i -= 1
    d = True
    c = 0
    res = ''
    for par in range(1,len(r2)-1):
        if r2[par][0]==[0]:
            if 2*a> (r2[par][1]-1)*b or r2[par][1]<2:
                res+='1'*r2[par][1]
            else:
                res+='+'
                res+=max((r2[par][1]-2),0)*'0'
                res+='-'
        else:
            res+='1'*r2[par][1]
    if len(r2)<=1:
        res = '0'*r2[0][1]
    else:
        res = max(0,r2[0][1]-1)*'0'+'+'+res
        res += '-'+max(0,r2[-1][1]-1)*'0'
    c = b
    for ch in res:
        if ch=='0':
            c+=a+b
        elif ch=='1':
            c+=a+2*b
        elif ch=='+':
            c+=2*(a+b)
        elif ch=='-':
            c+=2*a + b
    print(c)






