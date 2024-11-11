I=lambda:list(map(int,input().split()))
a,x=I(),I()
s,z=0,0
for i in range(3):
    if a[i]>x[i]:s+=a[i]-x[i]
    else:z+=x[i]-a[i]
print("NO" if 2*z>s else"YES")