n,a,b=map(int,input().split())
b-=a
print(b//2+b%2*min(a,n-b+1))