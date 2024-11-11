n,m=map(int,input().split())
food=list(range(1,m+1))
for i in range(n):
    k,*a=map(int,input().split())
    food &= set(a)
print(len(food))