def addition(list1):
    return len(list1) - 2 * list1.count(1)


n = int(input())
s = input()
k = list(map(int, s.split()))
x = k.count(1)
l = [-1]
for i in range(0, n):
    for j in range(i+1, n):
        l.append(addition(k[i:j+1]))
if len(s) == 1:
    print(k.count(0))
else:
    print(x + max(l))
