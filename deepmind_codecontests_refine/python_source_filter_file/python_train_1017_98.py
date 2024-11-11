n,k,s=map(int,input().split())
ans = (str(s) + ' ')*k + (str(s*2) + ' ')*(n-k)
print(ans[:-1])