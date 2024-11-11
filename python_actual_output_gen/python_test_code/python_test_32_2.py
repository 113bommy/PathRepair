s = input()
cnt = 0
sm = 0
i = len(s) - 1
while i != -1 and s[i] == 'a':
  i -= 1

while i > -1:
  if s[i] == 'b':
    cnt += 1
  else:
    sm += cnt
    sm %= 1000000007
    cnt *= 2
    cnt %= 10000000007
  i -= 1

print(sm % (10**9 + 7))