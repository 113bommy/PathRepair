n = int(input())
a = list(map(int, input().split()))
m = a[-1]
ans = []
for i in range(n):
      if a[n-i-1] > m:
        ans.append("0")
      else:
        ans.append(str(m+1-a[n-i-1]))

      m = max(a[n-i-1], m)

print(" ".join(ans[::-1]))
