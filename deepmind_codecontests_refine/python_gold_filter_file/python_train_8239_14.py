n=int(input())
l=list(map(int,input().split()))
s=sum(l);s=s//2;s+=1
a=l[0]
ind=[1]
if l[0]>=s:
    print(1)
    print(1)
else:
    for i in range(1,len(l)):
        if l[0]>=(2*l[i]):
            a+=l[i]
            ind.append(i+1)
    if a>=s:
        print(len(ind))
        for w in ind:
            print(w,end=" ")
    else:
        print(0)