n=int(input())
l1=[]
l2=[]
s1=0
s2=0
for i in range(n):
    a=int(input())
    if a>0:
        l1.append(a)
        s1+=a
    else:
        l2.append(abs(a))
        s2+=abs(a)
if s1>s2:
    print("first")
elif s2>s1:
    print("second")
else:
    leng1=len(l1)
    leng2=len(l2)
    leng=min(leng1,leng2)
    k=-1
    if leng1>leng2:
        k=1
    elif leng1<leng2:
        k=2
    for i in range(leng):
        if l1[i]>l2[i]:
            k=1
            break
        elif l1[i]<l2[i]:
            k=2
            break
    if k==-1:
        if a>0:
            print("first")
        else:
            print("second")

    elif k==1:
        print("first")
    else:
        print("second")