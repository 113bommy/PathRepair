n = int(input())
ct = 0
for i in range(1,n+1):
  if len(str(i)) % 2:
    ct += 1
print(ct)