a=[]
b=[]
s1=0
s2=0
n1=int(input())
t1=0
for i in range(n1):
    n=int(input())
    if n<0:
        b.append((-1)*n)
        s2+=(-1)*n
    else:
        a.append(n)
        s1+=n
    if i==(n1-1):
        if n<0:
            t1=2
        else:
            t1=1
if s1>s2:
    print("first")
elif s2>s1:
    print("second")
else:
    p=0
    for i in range(min(len(a),len(b))):
        if a[i]<b[i]:
            p=1
            break
        elif a[i]>b[i]:
            p=2
            break
    if p==0:
        if t1==1:
            p=2
        else:
            p=1
    if p==1:
        print("second")
    else:
        print("first")

