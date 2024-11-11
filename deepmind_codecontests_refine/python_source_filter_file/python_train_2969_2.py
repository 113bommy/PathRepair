a = input().split()
if a[-1] == 'week':
  if a[0] == '6':
    print(53)
  else:
    print(52)
else:
  day = int(a[0])
  if day <= 29:
    print(12)
  elif day == 30:
    print(11)
  else:
    print(7)