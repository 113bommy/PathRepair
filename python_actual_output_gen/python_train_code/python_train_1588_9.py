s = input().strip().replace('BC', 'D')
n = len(s)

count = 0
a_count = 0
print(s)
for i in range(n):
  if s[i] == 'A':
    a_count += 1
  elif a_count > 0 and s[i] == 'D':
    count += a_count
  else:
    a_count = 0

print(count)