n = int(input())
t = list(map(int, input().split()))
i1 = []
i2 = []
i3 = []
for i in range(1, n):
  if t[i] == 1:
    i1.append(i)
  elif t[i] == 2:
    i2.append(i)
  elif t[i] == 3:
    i3.append(i)
ai1 = len(i1)
ai2 = len(i2)
ai3 = len(i3)
if ai1 <= ai2 and ai1 <= ai3:
  mn = ai1
elif ai2 <= ai1 and ai2 <= ai3:
  mn = ai2
elif ai3 <= ai1 and ai3 <= ai2:
  mn = ai3
print(mn)
while i1 != [] and i2 != [] and i3 != []:
  print(i1[0] + 1, i2[0] + 1, i3[0] + 1)
  i1.remove(i1[0])
  i2.remove(i2[0])
  i3.remove(i3[0])