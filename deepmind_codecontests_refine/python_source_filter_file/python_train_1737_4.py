from itertools import combinations_with_replacement

l = []

for n in range(1, 20):
    st = set()
    for cmb in combinations_with_replacement((1, 5, 10, 50), n):
        st.add(sum(cmb))
    l.append(len(st))

n = int(input())
if n <= len(l):
    print(l[n-1])
else:
    print(n * 49 - 198)

