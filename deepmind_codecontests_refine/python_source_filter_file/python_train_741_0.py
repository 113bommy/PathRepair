import sys
sys.setrecursionlimit(10000000)
a, b = tuple([int(i) for i in input().split()])
save = {}
printl = ['']*(b)
data = ['']
for i in range(a):
    data.append(set())

for i in range(b):
    a = input().split()
    c = int(a[0])
    d = int(a[1])
    save[(c,d)] = i
    data[c].add(d)
    data[d].add(c)

done = set()

def search(prev, a, isforward):
    if isforward:
        good = '1'
        bad = '0'
    else:
        good = '0'
        bad = '1'
    for e in data[a]:       
        if e in done or e == prev:
            continue
        if (a,e) in save:
            p = save[(a,e)]
            if printl[p] != '':
            

                if printl[p] != good:
                    print('NO')
                    sys.exit()
            else:
                printl[p] = good
                search(a, e, not isforward)

        else:
            p = save[(e,a)]
            if printl[p] != '':
                
                if printl[p] != bad:
                    print('NO')
                    sys.exit()
            else:
                printl[p] = bad
                search(a, e, not isforward)
            
    done.add(a)

layer = {1}
good = '0'
bad = '1'

while len(layer) > 0:
    good, bad = bad, good
    new = set()
    for a in layer:
        for e in data[a]:       
            if e in done:
                continue
            if (a,e) in save:
                p = save[(a,e)]
                if printl[p] != '':
                    if printl[p] != good:
                        print('NO')
                        sys.exit()
                else:
                    printl[p] = good
                    new.add(e)

            else:
                p = save[(e,a)]
                if printl[p] != '':
                    
                    if printl[p] != bad:
                        print('NO')
                        sys.exit()
                else:
                    printl[p] = bad
                    new.add(e)
                
        done.add(a)
        layer = new




# try:
#     search(-1, 1, True)
# except Exception as e:
#     print(e.__class__)
print('YES')
print(''.join(printl))
            


