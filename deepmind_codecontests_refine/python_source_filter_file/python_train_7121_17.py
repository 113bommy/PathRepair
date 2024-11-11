# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
# import math 
# import collections
# import string
# ===================================
n = int(input())
q = [int(x) for x in input().split()]
ans = -1
if q.count(0): ans = 0
if q.count(5) >= 9: ans = "5" * (q.count(5) // 9 * 9) + "0" * q.count(0)
print(ans)