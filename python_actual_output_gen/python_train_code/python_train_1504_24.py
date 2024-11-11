n = int(input())
ans = ''
while n:
  ans = chr((n-1)%26+ord('a')) + ans
  n //= 26
print(ans)