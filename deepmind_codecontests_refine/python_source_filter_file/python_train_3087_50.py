#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

vow = {'a', 'e', 'i', 'o', 'u'}
n = int(input())
ans = []
for c in input():
    if len(ans) == 0 or (ans[-1] in vow and c not in vow) or ans[-1] not in vow:
        ans.append(c)
print(''.join(ans))