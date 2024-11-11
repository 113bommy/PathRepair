n = int(input())
a = [int(i) for i in input().split()]
for i in range(n-1):
    a.remove(min(a))
    if len(a) == 1:
        break
    a.remove(max(a))
    if len(a) == 1:
        break
print(a)