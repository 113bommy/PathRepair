n,k = map(int,input().split())
m = int(n/2)+n%2
ans = 'Yes' if m>=k else 'No'
print(ans)