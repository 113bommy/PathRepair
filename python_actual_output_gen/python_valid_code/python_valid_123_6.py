a = int(input())

x = []
for i in range(a):
    l,r = list(map(int, input().split()))
    x.append(r)

k = int(input())

if k - 1 < x[0]:print(a)
elif k - 1 == x[0]:print(a- 1)
else:
    for i in range(1, len(x)):
        if k - 1 < x[i]:print(a - i);break
        elif k - 1 == x[i]:print(a - i + 1);break
