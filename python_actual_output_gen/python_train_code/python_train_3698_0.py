USB = []
PS2 = []
u, p, b = map(int, input().split())
m = int(input())
for _ in range(m):
  a, s = input().split()
  if s[0] == 'U':
    USB += [int(a)]
  else:
    PS2 += [int(a)]
USB.sort()
PS2.sort()
ans = 0
n1 = min(u, len(USB))
n2 = min(p, len(PS2))
both = sorted(USB[n1:] + PS2[n2:])
print(n1 + n2 + min(len(both), b), sum(both[:b]) + sum(USB[:n1]) + sum(USB[:n2]))