# test!!!!!!!!!!!

from bisect import bisect_left, bisect_right

N = int(input())

S = list(input())

Q = int(input())

# {"a":[], "b":[], ..., "z":[]}
dict = {chr(ord('a') + i): [] for i in range(26)}


for i in range(N):
    dict[S[i]].append(i)

ans = []

for q in range(Q):
    query = list(input().split())
    if query[0] == '1':
        i, x = int(query[1])-1, query[2]
        now = S[i]
        if now == x:
            continue
        dict[now].remove(i)
        next_i = bisect_left(dict[x], i)
        dict[x].insert(next_i, i)
        S[i] = x
    else:
        start, end = int(query[1])-1, int(query[2])-1
        tmp_cout = 0
        for alf_array in dict.values():
            if len(alf_array) == 0:
                continue
            ss = bisect_left(alf_array, start)
            gg = bisect_right(alf_array, end)
            if gg- ss > 0:
                tmp_cout += 1
        ans.append(tmp_cout)

for i in ans:
    print(i)
