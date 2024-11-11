n = int(input())
a = list(map(int,input().split()))
ans = []
for i in range(n-1): ans.append(abs(a[i]-a[i+1]))
ans.append(abs(a[n-1]-a[0]))
if n == 2: print(min(ans),1)
else:
    print(min(ans),ans.count(min(ans)))