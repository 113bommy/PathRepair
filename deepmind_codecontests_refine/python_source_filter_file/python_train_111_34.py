n = input()
a = list(map(int, input().split()))

e = max(a)
b = []
c = e * 2

for i in range(len(a)):
    b.append(e-a[i])

while e <= c:
    if sum(b) > sum(a):
        print(e)
        break
    else:
        for j in range(len(b)):
            b[j] += 1
        e+=1



