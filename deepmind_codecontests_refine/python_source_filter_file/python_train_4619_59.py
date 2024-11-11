n=int(input())
c=0
for i in range(0,n):
    k=list(map(int,input().rstrip().split()))
    a=k.count("1")
    if a>=2:
        c+=1
print(c)