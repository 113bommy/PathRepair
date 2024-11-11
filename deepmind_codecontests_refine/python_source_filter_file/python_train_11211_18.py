n = int(input())
arr = list(map(int,input().split()))
if n==1:
    print(-1)
elif n==2:
    if len(set(arr))==1:
        print(-1)
    else:
        print(1,'\n',1)
else:
    print(1)
    print(arr.index(max(arr))+1)