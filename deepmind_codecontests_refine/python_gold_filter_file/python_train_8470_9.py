n=int(input())
for i in range(n+1,10000):
    k=i
    l=[]
    f=0
    while k>0:
        d=k%10
        if d not in l:
            l.append(d)
        else:
            f=1
            break
        k=k//10
    if f==0:
        print(i)
        break
