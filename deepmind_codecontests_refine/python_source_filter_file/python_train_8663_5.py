from sys import exit

def iis(): return map(int, input().split())
def ii(): return int(input())
def liis(): return list(map(int, input().split()))

s = input()

todos = {}
for i in range(len(s)):
  if s[i] not in todos:
    todos[s[i]] = 0
  todos[s[i]] += 1

ans = 1
maxi1 = 1
maxi2 = 1
maxi1c = s[0]
for k in todos:
  if todos[k] > maxi1:
    maxi1 = todos[k]
    maxi1c = k

def ans(s, c, d, n):
  ans = []
  for i in s:
    if i == c:
      ans.append(n)
    if i == d:
      n -= 1
  return ans

a = []
for i in todos:
  a.append([todos[i], i])

a = sorted(a)
answ = a[-1][0]
for i in range(len(a)):
  for j in range(len(a)):
    answ = max(answ, sum(ans(s, a[j][1], a[i][1], a[i][0])))
print(answ)
