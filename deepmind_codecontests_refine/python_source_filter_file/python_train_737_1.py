a=int(input())
l=list(map(int,input().split()))
c=-1
ma=0
if(l[0]!=0):
    print("1")
else:
    for i in range(1,a):
        if(0<l[i]<=(ma+1)):
            if(l[i]>ma):
                ma=l[i]
        else:
            c=i+1
            break
    print(c)
