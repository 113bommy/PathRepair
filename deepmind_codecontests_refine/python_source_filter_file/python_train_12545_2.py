k=int(input())
a=input()
n=len(a)
z='abcdfeghijklmnopqrstuvwxyz'[:k]
a=[a[i] for i in range(n)]
b=[0]*k
for i in range(n):
    if a[i]!='?':
        if a[n-1-i]!=a[i] and a[n-1-i]!='?':
            print('IMPOSSIBLE')
            break
        a[n-1-i]=a[i]
        b[z.find(a[i])]=1
else:
    g=a.count('?')
    g=g//2+g%2-b.count(0)
    if g<0:
        print('IMPOSSIBLE')
    else:
        for i in range(n):
            if a[i]=='?':
                if g>0:
                    a[i]='a'
                    g-=1
                else:
                    for j in range(k):
                        if b[j]==0:
                            a[i]=z[j]
                            b[j]=1
                            break
                a[n-1-i]=a[i]
        print(''.join(a))