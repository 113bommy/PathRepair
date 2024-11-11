l = input()
day = int(l.split()[0])
if 'month' in l:
  if day == 31: print(7)
  if day == 30: print(11)
  else: print(12)
else:
  if day in [1,2,3,4,7]: print(52)
  else: print(53)