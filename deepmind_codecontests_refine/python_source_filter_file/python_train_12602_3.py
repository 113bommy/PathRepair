n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

la = len(a)
lb = len(b)
l = min(la, lb)

for i in range(l):
    if a[i] < b[i]:
        print(1)
        break
    elif a[i] > b[i]:
        print(2)
        break
else:
    if la < lb:
        print(1)
    else:
        print(2)
