n = int(input())
s = input()
a = 'ACTG'
count = []
for j in range(n-3):
    x=0
    v=0
    for i in range(j,4+j):
        z = ord(s[i])
        az = abs(z-ord(a[x]))
        za = abs(abs(z-ord(a[x]))-26)
        if az<za:
            v += az
        else:
            v +=za
        x+=1
    count.append(v)
print(min(count))