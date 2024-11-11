n=int(input())
ar=list(map(int,input().split()))
day=0
for i in range(0,n):
    if ar[i]==i+1:
        day+=1
print(day)