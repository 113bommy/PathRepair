from math import ceil as c
a,b=map(int,input().split())
print(max(0,a-2*b),end=" ")
lo=1;hi=100000;ans=0
while lo<=hi:
    mid=(lo+hi)//2
    if (mid*(mid-1))//2>=b:ans=mid;hi=mid-1
    else:lo=mid+1
print(a-ans)