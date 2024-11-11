n, a, b = map(int, input().split())
s = input()
cnt = a+b
fc = b
for i in range(n):
  if s[n] == 'a' and cnt:
    print("Yes")
    cnt -= 1
  elif s[n] == 'b' and cnt and fc:
    print("Yes")
    cnt -= 1
    fc -= 1
  else:
    print("No")