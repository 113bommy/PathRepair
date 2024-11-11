from collections import defaultdict
from bisect import bisect_left
T = int(input())
for _ in range(T):
    s = input()
    t = input()
    length_s = len(s)
    s_dic = defaultdict(list)
    for i,x in enumerate(s):
        s_dic[x] += [i]
    now = 0  # current position
    ans = 1
    for x in t:
        if len(s_dic[x]) == 0:
            ans = -1
            break
        next_pos = bisect_left(s_dic[x],now+1)
        if next_pos == len(s_dic[x]):
            ans +=1
            now = s_dic[x][0]
        else:
            now = s_dic[x][next_pos]
    print(ans)