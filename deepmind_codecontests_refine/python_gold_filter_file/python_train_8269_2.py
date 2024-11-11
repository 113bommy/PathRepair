n=int(input())
c=0
for i in range(n):
    a,b=list(map(int,input().rstrip().split()))
    if a!=b:
        c=1
if c==1:
    print("Happy Alex")
else:
    print("Poor Alex")