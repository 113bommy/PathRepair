import sys
for q in range(int(sys.stdin.readline())):
    n, k = [int(j) for j in sys.stdin.readline().split()]
    d = [int(j) for j in sys.stdin.readline().strip()]
    ind = []
    for i in range(n):
        if not d[i]:
            ind.append(i)
    h = len(ind)
    for i in range(h):
        mov = min(ind[i] - i, k)
        # print(mov, k, d)
        k -= mov
        v = d[ind[i] - mov]
        
        d[ind[i] - mov] = 0
        d[ind[i]] = v
        if k == 0:
            break
    sys.stdout.write("".join(map(str, d)) + '\n')