a = []
b = []
n = int(input())
a.extend(list(map(int, input().split())))
m = int(input())
b.extend(list(map(int, input().split())))

c = set(a).union(set(b))
finish = 'No'
for i in range(m):
    if finish == 'Yes':
        break
    for j in range(n):
        if b[i] + a[j] not in c:
            print(a[j], b[i])
            finish = 'Yes'
            break