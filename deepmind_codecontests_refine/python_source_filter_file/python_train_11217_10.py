n=int(input())
arr=[int(s) for s in input().split()]
min_=min(arr)
max_=max(arr)
for i in range(0,n):
    if arr[i]==min_:
        a=i
if n==1 or (n==2 and min_==max_):
    print(-1)
else:
    print(1)
    print(a)
    