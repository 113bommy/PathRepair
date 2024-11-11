n = int(input())
v = []
q = 0
z = ['0' for i in range(n)]
for i in input().split() :
    v.append([int(i), q])
    q += 1
v.sort(reverse=True, key=lambda x : [x[0], -x[1]])
print(n+1)
 
def predictor(v, z, index_off, index_on, n) :
    #print(v)
    if n == 0 :
        for i in range(len(v)) :  
            if v[i][0] > 0 :
                v[i][0] -= 1
                z[v[i][1]] = '1'
            else : z[v[i][1]] = '0'
        print(''.join(z))
        return v
    
    for i in range(len(v)) :
        #print(index_off, i, n,  index_on)     
        if (index_off != i and (v[i][0] > 1 or (i == index_on and v[i][0] == 1))) :
            v[i][0] -= 1
            z[v[i][1]] = '1'
        else : z[v[i][1]] = '0'
    #print(101-n, ''.join(z), index_off, index_on)
    print(''.join(z))
    #if index_on < 13 : print(v)
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
        if y != -2 : y = q
        else : y += 1
        n -= 1
    return n
 
q = generator(v, z, n)
 
c = '0'*n
for i in range(q+1) : print(c)
