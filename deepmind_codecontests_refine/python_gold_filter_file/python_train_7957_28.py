s = input()
k = int(input())
a = list(map(int, input().split()))
sm = 0
for i in range(len(s)):
  sm = sm + a[ord(s[i]) - ord("a")]*(i+1)
mx = max(a)
for i in range(len(s)+1, len(s)+k+1):
  sm = sm + mx*i
print(sm)