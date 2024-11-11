from sys import stdin, stdout

n = int(stdin.readline())

c = [int(x) for x in stdin.readline().split()]
ops = []

turn = True

for x in range(n-1):
    newC = []
    newC2 = []
    op = []
    ind = c.index(x+1)
    if turn:
        if ind != 0:
            op.append(ind)
        op.append(n-x-ind)
        op += [1]*x
    else:
        op += [1]*x
        op.append(ind-x+1)
        if ind+1 != n:
            op.append(n-ind-1)
            
    ops.append([len(op)]+op)
    cur = 0
    for y in op:
        newC.append(c[cur:cur+y])
        cur += y
    for x in newC[::-1]:
        newC2 += x
    c = newC2
    #print(newC)
    #print(c)
    turn = not turn

out = []
for x in ops:
    if x[0] != 1:
        out.append(' '.join([str(y) for y in x]))
if c[0] != 1:
    out.append(' '.join(['1' for x in range(n)]))
print(len(out))
for x in out:
    print(x)
    
