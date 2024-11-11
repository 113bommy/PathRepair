'''p=input().rstrip().split(' ')
A=int(p[0])
l=['a','b']
if A>2:
    a='b'
    b='a';
    for i in range(2,A):
        c=l[i-1]+l[i-2];
        l.append(c)
C=list(l[A-1])
print(C)
for i in range(0,int(p[1])):
    s=input().rstrip()
    t=len(s)
    if t>len(C):
        print(0%1000000007)
    elif t==len(C):
        if s==''.join(C):
            print(1)
        else:
            print(0%1000000007)
    else:
        V=0;
        for j in range(0,len(C)-t+1):
            G=C[j:j+t]
            if ''.join(G)==s:
                V=(V+1)%1000000007;
        print(V%1000000007)
n=int(input())
if n%2!=0:
    print(n+1)
else:
    f=n;
    while(n%2==0):
        f+=(n//2)
        n=n//2;
    if n!=1:
        f+=1;
    print(f)'''


p=input().rstrip().split(' ')
n=int(p[0])
m=int(p[1])
c=int(p[2])
r=input().rstrip().split(' ')
s=input().rstrip().split(' ')
for i in range(0,n-m+1):
    A=0;
    for j in range(i,m+i):
        r[j]=(int(r[j])+int(s[A]))%c
        A+=1;
print(*r)
