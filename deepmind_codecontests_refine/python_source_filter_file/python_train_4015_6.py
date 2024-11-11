n=int(input())
a=input()
w=[]
p=[]

for i in range(n):
    if a[i]=='W':
        w.append(i)
if len(w)==0:
    print(1)
    print(n)
elif len(w)==n:
    print(0)
else:
    if w[0]!=0:
        p.append(w[0])
    for i in range(1,len(w)):
        if w[i-1]!=w[i]:
            p.append(w[i]-1-w[i-1])
    if w[-1]!=n-1:
        p.append(n-1-w[-1])
    print(len(p))
    for i in range(len(p)):
        print(p[i],end=' ')
