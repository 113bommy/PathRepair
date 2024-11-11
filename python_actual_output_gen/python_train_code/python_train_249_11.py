n, d = map(int, input().split())
C = [int(x) for x in input().split()]
if n == 1:
    print(0)
else:
    C.sort()
    first = 0
    last = n - 1
    curr_d = C[last] - C[first]
    if curr_d <= d:
        print(0)
    else:
        cnt = float('inf')
        aux = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                if C[j] - C[i] <= d:
                    aux = min(aux, (n - j) + i - 1)
                else:
                    break
            cnt = min(cnt, aux)
        if cnt == float('inf'):
            cnt = n
        print(cnt)