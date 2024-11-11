n,a,b,c,d = map(int, input().split())
S = input()
if "##" in S[a:max(c,d)]:
  print('No')
elif c > d and "..." not in S[b-2:max(c,d)]:
  print('No')
else:
  print("Yes")