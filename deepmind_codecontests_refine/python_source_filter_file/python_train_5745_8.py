def int_multiple():
    return  [int(c) for c in input().split()]

def int_single():
    return int(input())

def str_multiple():
    return [c for c in input().split()]

def str_single():
    return input()

# start

t = int_single()

res = []

for i in range(t):
    n, m, k = int_multiple()

    l = int_multiple()

    no = False
    for j in range(n-1):
        m -= l[j+1] - k - l[j]
        if m < 0:
            no = True
            break
    if no:
        res.append("NO")
    else:
        res.append("YES")

for r in res:
    print(r)
