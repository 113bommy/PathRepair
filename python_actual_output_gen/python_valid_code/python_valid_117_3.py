n = int(input())
s = input()
t = input()
for i in range(n):
  if s[i:] == t[:n-i]:
    print(n*2-i)
    exit()
print(n*2)