n,a,b,c,d = map(int, input().split())
s = input()

long_s = s[a:max(c,d)]
short_s = s[b-1:min(c,d)]

rocks = long_s.count("##")
change = short_s.count("...")

if rocks >= 1:
  print("No")
elif c > d and change == 0:
  print("No")
else:
  print("Yes")