t = int(input())
for i in range(t):
  n = int(input())
  s = input()
  if n == 2 and s[0] >= s[1]:
    print("NO")
  else:
    print("YES\n", s[0], s[1:])