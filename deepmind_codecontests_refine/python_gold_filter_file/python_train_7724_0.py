n = int(input())
v = []
q = 0
z = ['0' for i in range(n)]
for i in input().split() :
    v.append([int(i), q])
    q += 1
v.sort(reverse=True)
c = []

def predictor(v, z, index_off, index_on, n) :
    global c
    if n == 0 :
        for i in range(len(v)) :  
            if v[i][0] > 0 :
                v[i][0] -= 1
                z[v[i][1]] = '1'
            else : z[v[i][1]] = '0'
        #print(''.join(z))
        c.append(''.join(z))
        return v
    
    for i in range(len(v)) :    
        if (index_off != i and (v[i][0] > 1 or (i == index_on and v[i][0] == 1))) :
            v[i][0] -= 1
            z[v[i][1]] = '1'
        else : z[v[i][1]] = '0'
    c.append(''.join(z))
    return v
 
def generator(v, z, n) :
    y, x = -1, n-1
    q = 0
    while v[0][0] != 0 :
        if v[x-1][0] == 1 or v[x][0] == 0 : y = -2
        while v[x][0] == 0 : x -= 1
        if y >= 0 :
            while v[y][0]-1 == n :
                y += 1
                q += 1
        predictor(v, z, y, x, n)
        if y == -2 : y = q
        else : y += 1
        n -= 1
    return n
 
generator(v, z, n)
print(len(c))
for i in c : print(i)
