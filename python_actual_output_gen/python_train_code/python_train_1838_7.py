n=int(input())
k1=n//7
while (n-k1*7)%4!=0 and n>0 and k1>=0:
    k1-=1
if (n-k1*7)%4==0:
    print("4"*((n-k1*7)//4)+"7"*k1)
else:
    print(-1)


