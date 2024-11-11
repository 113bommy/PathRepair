import itertools

n, m, q = map(int, input().split())
abcd = [list(map(int, input().split())) for _ in range(q)]

A_list = list(itertools.combinations_with_replacement(range(1,m+1),n))

ans = 0
for A in A_list:
    sum = 0
    for a,b,c,d in abcd:
        if A[b-1] - A[a-1] == c:
            sum += d
    ans = max(ans, sum)

print(ans)