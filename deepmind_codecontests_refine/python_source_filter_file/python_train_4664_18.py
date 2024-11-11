x, y = map(int, input().split())
ans = max(0,4-x) + max(0,3-y)
if x==1==y: ans += 4
print(ans*100000)