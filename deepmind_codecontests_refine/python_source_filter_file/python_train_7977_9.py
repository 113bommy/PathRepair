N = int(input())

parent = []
children = []
leaf = []
for i in range(N + 5):
  parent.append(0)
  children.append([])
  leaf.append(False)
for n in range(2, N + 1):
  parent[i] = int(input())
  children[parent[i]].append(i)

for n in range(1, N + 1):
  if len(children[n]) == 0 and parent[n]:
    leaf[n] = True

for n in range(1, N + 1):
  if not leaf[n]:
    cnt = 0
    for each in children[n]:
      cnt += leaf[each]
    if cnt < 3:
      print("No")
      quit()


print("Yes")    