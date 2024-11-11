n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in a:
    if (5-i)>k:
        c+=1
print(c//3)