def povorot(a,b):
    for i in range(m+1):
        for j in range(n+1):
            b[j][i] = a[i][j]



def otr(b,c):
    for i in range(1,m+1):
        for j in range(1,n+1):
            c[j-1][i-1] = b[j][i]



def mashtab(c,d,e):
    r = 0
    for i in range(n):
        tmp = ''.join(c[i])
        for j in range(len(tmp)):
            d[r][j] = tmp[j]
            d[r+1][j] = tmp[j]
        r = r + 2
    r = 0
    for i in range(m):
        for j in range(2 * (n)):
            e[j][r] = d[j][i]
            e[j][r+1] = d[j][i]
        r = r + 2    


n,m = map(int,input().split())
a = [ [0] * (n+1) for i in range(m+1) ]
for i in range(1,m+1):
    tmp = input()
    tmp.rstrip()
    for j in range(len(tmp)):
        a[i][j+1] = tmp[j]
b = [ [0] * (m+1)  for i in range(n+1) ]
povorot(a,b)
c = [ [0] * (m) for i in range(n) ]
otr(b,c)
d = [ [0] * (2 * (m)) for i in range(2 * (n)) ]
e = [ [0] * (2 * (m)) for i in range(2 * (n)) ]
mashtab(c,d,e)
for i in range(len(e)):
    for j in range(len(e[i])):
        print(e[i][j],end = ' ')
    print()