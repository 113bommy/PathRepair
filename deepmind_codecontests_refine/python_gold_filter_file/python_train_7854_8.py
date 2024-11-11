n=int(input())
arr=[]
for i in range(n):
    a,b=list(map(int,input().split()))
    arr.append([a,b])
arr.sort(key=lambda x:x[0]+float(x[1])/20000000);
end=-1
for i in range(len(arr)):
    if arr[i][1]>=end:
        end=arr[i][1]
    else:
        end=arr[i][0]

print(end)