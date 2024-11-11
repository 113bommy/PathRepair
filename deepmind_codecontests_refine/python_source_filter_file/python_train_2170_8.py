n=int(input())
a=list(map(int,input().split()))
x,y=sum(x%2==0 for x in l),n-x
print(3**n-2**x)