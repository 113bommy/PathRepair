n,m = map(int,input().split())
arr = [-1]
if(m!=0):
    arr = list(map(int,input().split()))
    arr.append(-1)  
    arr.sort()
count = 1
flag = 0
for i in range(1,m):
    if(arr[i]-arr[i-1]==1):
        count+=1
    else:
        count = 1
    if(count>=3):
        flag = 1
if(m==0):
    print("YES")
elif(flag or arr[-1] == n or arr[1] == 1):
    print("NO")
else:
    print("YES")