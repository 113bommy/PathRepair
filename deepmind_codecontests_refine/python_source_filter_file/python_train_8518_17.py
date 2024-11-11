S=input()
A = "AKIHABARA".split("A")
for i in range(2**4):
  ans = ""
  for j in range(4):
    if i>>j&1: ans += "A"
    ans += A[j]
  if S == ans:
    print("YES")
    break
else:
  print("NO")