def solve(n, p, array):
    array.sort()
    array1 = [i+1-array[i] for i in range(n)]
    m = min(array1)

    min_x = 1 - min(m, 0)
    valid = [1 for i in range(n)]
    max_v = n - 1
    
    for i in range(n):
        a = array1[i] + min_x
        if (i + 1) % p == 0:
            max_v = min(array[i] - min_x - 1, max_v)
        if a < i + 1:  
            cur = (-a) % p
            end = min(i + 1 - a, max_v)
            while cur < end:
                valid[cur] = 0
                cur += p
        
    res = []
    for i in range(max_v + 1):
        if valid[i]:
            res.append(min_x + i)
    print(len(res))
    print(*res)
                

    
n, p = [int(s) for s in input().split()]
array = [int(s) for s in input().split()]
solve(n, p, array)