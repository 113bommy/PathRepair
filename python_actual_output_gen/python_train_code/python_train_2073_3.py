from itertools import combinations_with_replacement as comb

n,m,q = map(int, input().split(' '))
lis = [list(map(int, input().split())) for _ in range(q)]
tes = comb(range(1,m))
res = 0
for i in tes:
    te = 0
    for a,b,c,d in lis:
        if c == i[b-1] - i[a-1]:
            te += d
    res = max(te,res)
print(res)