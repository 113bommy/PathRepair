n=int(input())
k=int(input())
x=int(input())
y=int(input())
print(
x*min(n,k)+y*max(0,n-k)
)