
n = int(input())
st = str(input())

c = 0
for i in st[:len(st)-10]:
    if i == '8':
        c += 1

if c < (len(st) - 10) // 2 + 1:
    print ('NO')
else:
    print ('YES')
