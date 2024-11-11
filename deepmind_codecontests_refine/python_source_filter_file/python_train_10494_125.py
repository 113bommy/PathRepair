n, a, b, c, d = map(int, input().split())
s = input()

if "##" in s[a:c+1] or "##" in s[b:d+1] :
  print("No")
elif c<d:
  print("Yes")
elif "..." in s[b-2:d] :#以下 d<c の場合
  print("Yes")
else :
  print("No")
