n = int(input())
ans = ''
while n > 0:
  n -= 1
  ans += chr(ord('a')+ans%26)
  n //= 26
print(ans[::-1])