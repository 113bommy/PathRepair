n = int(input())
a = [int(i) for i in input().split()]
a.sort()
t = 1
for num in a:
    if num > t:
        t += 1
print(t)