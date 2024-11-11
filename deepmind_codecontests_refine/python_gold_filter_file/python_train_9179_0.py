n = int(input())
s = input()

ab = ba = 0

k = 0

for i in range(2, len(s)+1, 2):
  if s[i-2:i] not in ['ab','ba']:
    k += 1

print(k)
for i in range(2, len(s)+1, 2):
  if s[i-2:i] not in ['ab','ba']:
    print('ab',end='')
  else:
    print(s[i-2:i],end='')
print()