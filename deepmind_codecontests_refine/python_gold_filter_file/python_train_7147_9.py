(n, k) = map(int, input().split())

lst = []
for x in input().split():
    lst.append(int(x))

array = []
for x in input().split():
    array.append(int(x))

mass1 = [0]
for x in range(n):
    mass1.append(mass1[-1] + lst[x])

mass2 = [0]
for x in range(n):
    mass2.append(mass2[-1] + lst[x] * array[x])

ans = 0
for x in range(1, n - k + 2):
    ans = max(ans, mass2[x - 1] + (mass1[x + k - 1] - mass1[x - 1]) + (mass2[-1] - mass2[x + k - 1]))
    #print(ans, x)

print(ans)
