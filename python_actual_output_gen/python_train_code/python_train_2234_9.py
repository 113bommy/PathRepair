
n = int(input())
st = str(input())

c = 0
for i in st[:len(st)-11]:
    if i == '8':
        c += 1

if c < (len(st) - 11) // 2:
    print ('NO')
else:
    print ('YES')
