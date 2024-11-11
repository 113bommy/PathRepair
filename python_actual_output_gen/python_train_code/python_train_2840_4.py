a,b = map(int, input().split(":"))
c = int(input())
k = (a*60 + b+c) % 1439

h = k // 60; m = k % 60

if h >= 0 and h <= 9:
    print('0'+str(h)+':',end='')
else:
    print(str(h)+':',end='')

if m >= 0 and m <= 9:
    print('0'+str(m),end='')
else:
    print(str(m),end='')