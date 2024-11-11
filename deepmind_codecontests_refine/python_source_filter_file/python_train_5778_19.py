from math import sqrt
a=[0]+[int(i) for i in input().split()]
S=sqrt(3)*(a[6]*a[5]+a[1]*a[2]+a[3]*a[4])/2 + (a[1]-a[4])*(a[1]-a[4])*sqrt(3)/4
print(int(S*4/sqrt(3)))