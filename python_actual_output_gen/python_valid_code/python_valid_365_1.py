s = input().strip()
t = input().strip()
diff = len(s) - 1
for i in range(len(t)):
  if s[i] != t[i]:
    diff = i
    break
for i in range(diff + 1, len(t)):
  if s[i] != t[i - 1]:
    print(0)
    import sys; sys.exit()
start = diff
while start != 0 and s[start - 1] == s[diff]:
  start -= 1
print(diff - start + 1)
print(' '.join(map(str, range(start + 1, diff + 2))))
