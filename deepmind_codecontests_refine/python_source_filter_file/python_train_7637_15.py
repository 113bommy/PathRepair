

n=int(input())

arr=[0]*n

for i in range (0,n):
    x=int(input())
    arr.append(x)

ans=0;
ans+= arr[0]+1

for i in range (0,n-1):
    ans+= 2 + abs(arr[i]-arr[i+1])

print(ans)