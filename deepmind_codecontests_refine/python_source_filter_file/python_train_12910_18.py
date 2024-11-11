def check(p):
    i = 0
    for _ in range(k):
        total = 0
        while total+n_list[i] <=p:
            total += n_list[i]
            i += 1
            if i == n:
                return n
    return i

def solve():
    left   = 0
    right  = 10**5 * 10**4
    middle = 0
    while left-right > 1:
        middle = (left+right)//2
        temp_ans = check(middle)
        if temp_ans >= n:
            right = middle
        else:
            left  = middle
    return right

n,k = map(int,input().split())
n_list = [int(input()) for _ in range(n)]
ans = solve()
print(ans)
