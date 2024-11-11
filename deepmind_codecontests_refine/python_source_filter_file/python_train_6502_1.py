#komandy
n, m=map(int,input().split())
k_max=(n-m+1)*(n-m)/2
if n%m==0 and m!=1:
    k_min=n*((n/m)-1)/2

else:
    ost=n%m
    k_min=((n//m)*((n//m)-1)*(m-ost)+(n//m+1)*((n//m))*(ost))/2
print(int(k_min), int(k_max))