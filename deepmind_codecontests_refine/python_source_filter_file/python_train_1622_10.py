def p3(a, start, sol):
    if not a:
        return 6
    if sum(a) != 0:
        sol.append([1+start,len(a)+start])
        return sol
    for i,n in enumerate(a):
        if sum(a[:i]) != 0:
            sol.append([1+start,i+start])
            sol = p3(a[i:], start+i, sol)
            return sol
            

n = input()
a = [int(i) for i in input().split(' ')]

#n = 3
#a = [1, 2, -3]
#n = 8
#a = [9, -12, 3, 4, -4, -10, 7, 3]
#n=4
#a=[1,2,3,-5]

#a=[0,1,0,1,0,1,0,1,0,1]

n=1
a=[0]

sol = p3(a, 0, [])

if not sol:
    print('NO')
else:
    print('YES')
    print(len(sol))
    for b in sol:
        print(' '.join([str(i) for i in b]))
