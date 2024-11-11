import collections
N = int(input())
a = list(map(int, input().split()))
a = collections.Counter(a)
a = a.most_common()
ans = 0
for i in range(len(a)):
  if a[i][0] <= a[i][1]:
    ans += a[i][1] - a[i][0]
  else:
    ans += a[i][0]
    
print(ans)