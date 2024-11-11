n=int(input())
a1,b1=map(int,input().split())
a2,b2=map(int,input().split())
a3,b3=map(int,input().split())
k1=a1
k2=a2
k3=a3
n=n-k1-k2-k3
for i in range(n) :
    if k3<b3 :
        k3=k3+1
    else :
        if k2<b2 :
            k2=k2+1
        else :
            k1=k1+1
print(k1,k2,k3)


