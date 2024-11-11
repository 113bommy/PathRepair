n, m = map(int, input().split())
arr = []
pal = ''
rev = ''
for i in range(n):
    temp = input()
    arr.append(temp)
    if temp == temp[::-1]:
        rev = temp
    for j in range(i):
        if arr[i] == arr[j][::-1]:
            pal = arr[i] + pal + arr[j]
if rev != '':
    l = int((len(pal) + 1) / 2)
    pal = pal[0:l] + rev + pal[l:]
if pal == '':
    print(0)
else:
    print(len(pal))
    print(pal)