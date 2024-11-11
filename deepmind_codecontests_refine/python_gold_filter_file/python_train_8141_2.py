from sys import stdin
from collections import deque
mod = 10**9 + 7
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations

# t = int(input())
#
# t = int(input())
#
# for _ in range(t):
#     n = int(input())
#
#     z = len(str(n))
#     ans = 9*(z-1)
#     if int(str(n)[0]*z)>n:
#         ans+=int(str(n)[0])-1
#     else:
#         ans+=int(str(n)[0])
#     print(ans)
#
#
t = int(input())

for _ in range(t):

    s = input()
    ans = set()
    for i in range(len(s)-2):
      if i+1 not in ans:
        if s[i] == 't' and s[i+1] == 'w' and s[i+2] == 'o':

            try:
                if s[i+3] == 'o':
                    ans.add(i+2)
                else:
                 try:
                    if s[i+3] == 'n' and s[i+4] == 'e':
                        ans.add(i+3)
                    else:
                        ans.add(i+2)
                 except:
                     ans.add(i+2)
            except:
                ans.add(i+2)

        if s[i] == 'o' and s[i+1] == 'n' and s[i+2] == 'e' and i+2 not in ans and i+3 not in ans:
            ans.add(i+2)


    print(len(ans))
    print(*ans)







