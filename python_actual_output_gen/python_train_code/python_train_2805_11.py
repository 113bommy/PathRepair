n,t=map(int,input().split())
a=list(map(int,input().split()))
index=1
while(index<n):
    if index==t:
        break
    else:
        print(index)
        index+=a[index-1]
if index==t:
    print('YES')
else:
    print('NO')
