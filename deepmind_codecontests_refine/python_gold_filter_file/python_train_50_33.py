buttons, bulbs = map(int, input().split())
state = []

for i in range(buttons):
    t = input().split()
    for j in t[1:]:
        state.append(int(j))

uniq = list(set(state))
if len(uniq) == bulbs:
    print('YES')
else:
    print("NO")
