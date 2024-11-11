K = int(input())
AT = list(map(int,input().split()))

A=reversed(AT)
s = 2;b = 1;lis=[]
for i in A:
    ns = i
    if s > ns:
        ns +=(((s-ns)//i)*i)
        if s > ns:
            ns+i
    s = ns
sn = s
for i in AT:
    sn = sn-sn%i

if sn!=2:
    print(-1)
    exit()
b = 1
AT.reverse()
for i in AT:
    b=b-b%i
    nb = i
    if b > nb:
        nb +=(((b-nb)//i)*i)
        if b > nb:
            nb+i
    b= (nb+i-1)
print(s,b)
