list = []
for i in range(int(input())):
    list.append(int(input()))
set1 = set(list)
if len(set1) != 2:
    print("NO")
elif list.count(set1.pop()) != list.count(set1.pop()):
    print('NO')
else:
    print('YES')
    Set = set(list)
    print(Set.pop(),Set.pop())