n=int(input())
arr=list(map(int,input().split()))
a,b=map(int,input().split())
start=a-1
end=b-1
ans=sum(arr[start:end+1])
print(ans)