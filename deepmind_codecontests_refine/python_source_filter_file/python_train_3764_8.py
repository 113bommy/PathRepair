a=list(map(int,input().split()))
x=a[3]

ans1=a[0]+a[1]-x
ans2=a[1]+a[2]-x
ans3=a[0]+a[2]-x

print(ans1," ",ans2," ",ans3)
