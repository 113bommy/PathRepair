n,m=map(int,input().split())
s=n//m
j=n%m
a=s+j
p=j*a*(a-1)//2
q=(m-j)*s*(s-1)//2
print(p+q,end=' ')
mx=n-m+1
print(mx*(mx-1)//2)
