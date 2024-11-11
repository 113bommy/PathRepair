n = int(input())
s = input().split()
a = []
for x in s:
    a.append(int(x))
count = 1
for i in range(1, 3002):
    if i not in a:
        print(i)
        break