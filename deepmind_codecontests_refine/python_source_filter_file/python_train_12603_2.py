n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

la = len(a)
lb = len(b)
l = min(la, lb)

for i in range(l):
    if a[i] < b[i]:
        print(0)
        break
    elif a[i] > b[i]:
        print(1)
        break
else:
    if la < lb:
        print(0)
    else:
        print(1)
