s = input()
n = int(input())
current = 'z' * 101
for p in range(n):
  page = input()
  if page.startswith(s) and current > page:
    current = page
if current == 'z' * 101:
  current = s
print(current)