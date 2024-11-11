a, b = map(int, input().split())
ratings = list(map(int, input().split()))
values = {}
for x in range(a):
    values[ratings[x]] = x + 1
if len(values) >= b:
    print("YES")
    n = 0
    students = []
    for x in values.values():
        students.append(x)
        n += 1
        if n == b:
            break
    print(" ".join(map(str, students)))
else:
    print("NO")