from math import ceil 
n,k=map(int,input().split())
temp=ceil(n/2)
if n%2==0:
    temp*=n
else:
    temp*=temp
    temp+=(ceil(n/2)*(n//2))
if k>temp:
    print("NO")
else:
    print("YES")
    for i in range(n):
        if i%2==0:
            for j in range(n):
                if j%2==0 and k!=0:
                    print("L",end="")
                    k-=1
                else:
                    print("S",end="")
        else:
            for j in range(n):
                if j%2!=0 and k!=0:
                    print("L",end="")
                    k-=1
                else:
                    print("S",end="")
        print()