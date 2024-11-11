result = []
data = []
number, m = map(int, input().split())
for a in range(number):
    b, c = map(int, input().split())
    for d in range(b, (c + 1)):
        data.append(d)
data = set(data)
for a in range(1, m):
    if a not in data:
        result.append(a)
if len(result) > 0:
    print(len(result))
    for e in result:
        print(e, end=" ")
else:
    print(0)
