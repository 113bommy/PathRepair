n,k=map(int,input().split())
l=list(map(int,input().split()))
x=round((2*k)**(0.5))
x=x-1
x=x*(x-1)//2
print(l[n-x-1])