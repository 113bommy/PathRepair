n,k = map(int,input().split())
m = int(n/2)+n%2
ans = 'YES' if m>=k else 'NO'
print(ans)