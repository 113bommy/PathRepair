import atexit
import io
import sys
from collections import Counter
from math import log
import math
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())



# R = lambda : map(int,input().split())
# # t = int(input())
# # for i in range(t):
# n,k = map(int,input().split())
# l = list(R())
# c = Counter(l)
# bts_avail = k*8 // n
# disk_size = math.ceil(math.log(len(c),2))*n
# if disk_size<=8*k:
#     print(0)
# else:
#     dl = list(c.values())
#     len_dl = len(dl)
#     dl.sort()
#     ans =0
#     for i in dl:
#         len_dl-=1
#         ans+=i
#         if math.log(len_dl,2)<=bts_avail:
#             break
#
#     print(ans)
# n, m = map(int, input().split())
# a = sorted(map(int, input().split()))
# b = [0]
# print(a)
# a += [1 << 30]
# print(a)
# for i in range(n):
#     if a[i] < a[i+1]:
#         b += [i+1]
# print(b)
#
#
# print(1<<8)
# print(n-max((y-x for x,y in zip(b,b[1<<8*m//n:])),default=n))

n,i= map(int, input().split())
l= list(map(int, input().split()))
k= (8*i)//n
K= 2**k
l.sort()
temp= [0]
for i in range(1,n):
    if(l[i-1]!=l[i]):
        temp.append(i)
# print(temp)
if(len(temp)<=K):
    print(0)
else:
    print(n - max(temp[i+K]-temp[i] for i in range(len(temp)-K)))