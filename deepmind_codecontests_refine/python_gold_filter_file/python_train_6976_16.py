n = int(input())
a = [i for i in input().split()]
a2 = a.copy()
for i in range(n):
    for j in reversed(range(i+1, n)):
        if a[j][1] < a[j-1][1]:
            a[j], a[j-1] = a[j-1], a[j]
for s in range(n):
    minj = s 
    for t in range(s+1, n):
        if a2[t][1] < a2[minj][1]:
            minj = t
    if a2[s] != a2[minj]:
        a2[s], a2[minj] = a2[minj], a2[s]
print(*a)
print("Stable")
print(*a2)
if a == a2:
    print("Stable")
else:
    print("Not stable")
