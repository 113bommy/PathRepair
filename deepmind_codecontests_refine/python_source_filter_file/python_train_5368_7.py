def solve():
    ans = float('inf')
    n , m , k = map(int, input().split())
    arr = [list(map(int, input().split())) for i in range(m)]
    if k == 0 :
        return -1
    goal = set(map(int, input().split()))
    for i in arr :
        [u , v , l] = i 
        if (u in goal) ^ (v in goal) :
            ans = min(ans , l)
            print(i)
    return ans if ans != float('inf') else -1
print(solve())            