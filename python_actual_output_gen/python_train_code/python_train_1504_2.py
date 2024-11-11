n = int(input())
s = []
while n > 0:
  s.append(chr((n-1) % 26 + 97))
  n = n // 26
print(''.join(list(reversed(s))))