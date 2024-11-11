m = int(input())
mm = m
ms = []
c = 0
a=1
b=1
if m < 20:
    print(m)
    exit(0)
for x in range(1,len(str(m)),+1):
    ms.append('9')
if str(m)[0] != '1':
    ms.insert(0,str(int(list(str(m))[0])-1))
ms_int = int(''.join(ms))
b_int = m-ms_int
wyn = 0
for x in ms:
    wyn+=int(x)
for x in list(str(b_int)):
    wyn+=int(x)
print(wyn)