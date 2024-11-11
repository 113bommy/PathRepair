n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
d = {}

for i in a:
    for j in b:
        if j%i == 0:
            cur = j//i
            if cur in d:
                d[cur] += 1
            else:
                d[cur] = 1
l = sorted(d.items(), key = lambda x: x[0], reverse = True)
print(l[0][1])
