n = int(input())
d = {1:1}
L = [1,1]
for i in range(n-1):
    a = int(input())
    if a not in d:
        d[a] = 0
    d[a] += 1
    L.append(a)
for i in d.keys():
    d[L[i]] -= 1
print(d)
for i in d.values():
    if i < 3:
        print("NO")
        quit()
print("YES")