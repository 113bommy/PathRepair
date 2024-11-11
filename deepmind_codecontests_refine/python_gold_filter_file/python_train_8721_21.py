n,m=map(int,input().split())
a=list(map(int,input().split()))
print('NYoe s'[len([i for i in a if i>=sum(a)/4/m])>=m::2])