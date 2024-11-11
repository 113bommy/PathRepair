def solve(l, n, a, b):
    i = 0
    j = n - 1
    cost = 0
    min_cost = min(a, b)
    while i < j:
        if l[i] == 2 and l[j] == 2:
            cost += min_cost
        elif l[i] == 2 or l[j] == 2:
            if l[i] == 0 or l[j] == 0:
                cost += a
            else:
                cost += b
        elif l[i] != l[j]:
            return -1
            
        i += 1
        j -= 1
    
    if i == j and l[i] == 2:
        cost += min_cost
    
    return cost

            

n, a, b = list(map(int, input().strip().split()))
l = list(map(int, input().strip().split()))
print(solve(l, n, a, b))