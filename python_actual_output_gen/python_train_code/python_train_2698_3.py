# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# import string
# ===================================
n = int(input())
q = [str(x) for _ in range(n) for x in input().split() ]
ans = [[q.count(x), x] for x in set(q)]
ans.sort(reverse = True)
print(ans[0][1])
