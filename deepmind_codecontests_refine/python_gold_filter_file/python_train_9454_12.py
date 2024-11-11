N = int(input())
import itertools

d = {}
k = 1
while k*(k-1)/2 < 10**5:
    d[int(k*(k-1)/2)] = k
    k += 1

if N not in d.keys():
    print("No")

else:
    print("Yes")
    k = d[N]
    output = [[] for _ in range(k)]
    print(k)

    comb_list = list(itertools.combinations(list(range(k)), 2))
    for n, comb in zip(range(1, N+1), comb_list):
        output[comb[0]].append(n)
        output[comb[1]].append(n)

    length = len(output[0])
    for l in output:
        print(length, *l)