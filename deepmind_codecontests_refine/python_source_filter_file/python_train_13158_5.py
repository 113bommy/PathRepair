def readInt():
    return int(input())

def readIntList():
    l = input()
    return list(map(int, l.split(" ")))

def build(tree, elem, v, l, r):
    if(l == r):
        tree[v] = elem[l]
    else:
        m = (l + r) // 2
        build(tree, elem, v * 2, l, m)
        build(tree, elem, v * 2 + 1, m + 1, r)
        tree[v] = max(tree[v * 2], tree[v * 2 + 1])

def find_max(tree, v, l, r, tl, tr):
    if(l > r):
        return (0, 10000)
    else:
        if(tl == l and tr == r):
        #   print(tl, tree[v])
            return (tree[v], tl)
        else:
            tm = (tl + tr) // 2
            m1 = find_max(tree, v * 2,     l,              min(r, tm), tl,     tm)
            m2 = find_max(tree, v * 2 + 1, max(l, tm + 1), r,          tm + 1, tr)
            if(m1[0] == m2[0]):
                if(m1[1] > m2[1]):
                    return m2
                else:
                    return m1
            else:
                if(m1[0] > m2[0]):
                    return m1
                else:
                    return m2

            #return max(m1, m2)


(n, k) = readIntList() 
laws = readIntList()

tree = 4*n*[0]

m = sum( laws [0 : k] )
n = len(laws)
maxs = [m]
for i in range(1, n - k + 1) :
    m -= laws[i - 1];
    m += laws[i + k - 1];
    maxs.append(m)

mn = len(maxs) - 1

#print(mn, maxs)
#build(tree, maxs, 1, 0, len(maxs) - 1)
#print(tree)
#print( find_max(tree, 1, 1, len(maxs) - 1, 0, len(maxs) - 1) )

#last_max = ((0, 0), (0, 0))
#last_max_i = 0
m1 = 0
m2 = 0

#for i in range(0, mn - k):
#   m1 = (maxs[i], i)
#
#   if( i + k > last_max[1][1] ):
#       m2 = find_max(tree, 1, i + k, mn - 1, 0, mn - 1)

#   if( (m1[0] + m2[0]) > last_max[0][0] + last_max[1][0] ):
#       last_max = (m1, m2)

#print( last_max )
#print( last_max[0][1] + 1, last_max[1][1] + 1 )

#print(( last_max_i + k, mn - 1))
#for i in range( last_max_i + k, mn):

#   if( maxs[i] + maxs[last_max_i] == last_max ):
#       last_max_i = (last_max_i, i)
#       break

#print (last_max_i[0] + 1, last_max_i[1] + 1)
m1 = maxs[mn - k]
i1 = 0
m2 = maxs[mn]
i2 = 0
#print ( list(range(mn - k, -1, -1)) )

a = (mn + 1) * [0]

for i in range(mn - k, -1, -1):     
    if( maxs[i + k] >= m2):
        m2 = maxs[i + k]
        i2 = i + k
    a[i] = (maxs[i] + m2, i2);


#   print( i, i + k, i1, i2, maxs[i], maxs[i + k - 1])
#print(a)

ms = 0
#print(list(range(0, mn - k)))
for i in range(0, mn - k):
    if(a[i][0] > ms):
        i1 = i
        i2 = a[i][1]
        ms = a[i][0]

print(i1 + 1, i2 + 1)