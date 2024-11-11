import sys

input = sys.stdin.readline

n = int(input())

s = [int(x) for x in input().strip()]

f = list(map(int, input().split()))

started = False
for i in range(len(s)):
  if f[s[i]-1] >= s[i]:
    started = True
    s[i] = f[s[i]-1]
  elif started and f[s[i]-1] < s[i]:
    break

print(''.join([str(x) for x in s]))
