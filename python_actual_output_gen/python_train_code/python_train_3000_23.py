l = [0,0,0,0,0]
for i in filter(lambda x: x < 5, map(int, input().split(' '))):
    l[i] += 1
if any(l[i] == i for i in range(1,4)) or (l[2] == 1 and l[4] == 2):
    print("YES")
else:
    print("NO")
