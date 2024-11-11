def isPalindrom(p):
    t =  ( ''.join( reversed(p) ))
    return t == p

def solve(p):
    palin = []
    pairs = []
    for i in p:
        rever = ''.join(reversed(i))
        if rever in p and not isPalindrom(i) and not rever in pairs:
            pairs.append(i)
        elif isPalindrom(i):
            palin.append(i)
            
    res = ''
    if palin:
        res = res + palin[0]
    for i in pairs:
        res = i + res + ''.join(reversed(i))
    print(len(res))
    print(res)
    



problem = []
m, n = input().split(' ')
m = int(m)
n = int(n)

for i in range(m):
    l = input()
    problem += [ l ]

solve(problem)

    