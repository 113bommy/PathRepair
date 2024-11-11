a = input()
a = a.split(' ')
for i in range(len(a)):
    a[i] = int(a[i])

b = []
d = [0,0]

for i in range(a[0]):
    c = input()
    c = c.split(' ')
    d[0] = int(c[0])
    d[1] = int(c[1])
    b += [d]
    d = [0,0]

f =  [0,0]
f[0] = a[1]//60
f[1] = a[1] % 60
def resitev():
    s = [0,0]
    if (b[0][0]*60 + b[0][1] >= f[0]*60 + f[1] + 1): 
        print(0,0)
        return
    for i in range(a[0]-1):
        s[0] = b[i+1][0]-b[i][0]
        s[1] = b[i+1][1]-b[i][1] - 2
        if s[0]*60 + s[1] >= 2*(f[0]*60+f[1]):
                if f[1]+b[i][1] + 1 < 60:
                    print(f[0]+b[i][0],f[1]+b[i][1] + 1)
                    return
                else:
                    print(f[0]+b[i][0]+1,(f[1]+b[i][1] + 1)%60)
                    return

    if b[a[0]-1][1]+f[1] +1 < 60:
        print(b[a[0]-1][0]+f[0],b[a[0]-1][1]+f[1] + 1)
        return
    print(b[a[0]-1][0]+f[0]+1,(b[a[0]-1][1]+f[1]+1)%60)
    return
resitev()
