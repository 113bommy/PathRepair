n, m = map(int, input().split())
inf = int(1e12)
ls = [int(i) for i in input().split()]
ls.sort()
ls = [-inf] + ls + [inf]

st = set()

for i in range(n+1):
    if i != 0:
        if ls[i] + m < ls[i+1] and (ls[i+1] - (ls[i] + m) >= m):
            st.add(ls[i] + m)

    if i != n:
        if ls[i+1] - m > ls[i] and (ls[i+1]-m-ls[i] >= m):
            st.add(ls[i+1] - m)

print(len(st))