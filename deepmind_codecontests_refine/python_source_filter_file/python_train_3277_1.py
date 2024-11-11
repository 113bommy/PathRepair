from sys import stdin
def read(): return map(int, stdin.readline().split())

s = stdin.readline()[:-1]
read()
n = len(s)
print(n)
cnt = [0]*n
for x in read():
  cnt[min( x, n - x + 1 ) - 1] += 1

for i in range(1,n):
  cnt[i] += cnt[i-1]

ans = ['?']*n
for i in range(n):
  if cnt[min(i,n-i-1)]%2 == 0:
    ans[i] = s[i]
  else:
    ans[i] = s[n-i-1]

print("".join(ans))
