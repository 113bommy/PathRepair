n = int(input())
l = [0]*(55556)
i = 2
while i <= 55555:
    j = 2
    while i*j <= 55555:
        l[i*j] = 1
        j += 1
    i += 1
ans = []
for i in range(3,55556):
    if l[i]:
        continue
    if ((i-1)//2)%5 == 0:
        ans.append(i)
print(ans[:n])