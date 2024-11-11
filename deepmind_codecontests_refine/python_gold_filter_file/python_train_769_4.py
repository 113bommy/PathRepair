import sys
from math import sqrt
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

n = int(input())
size = []
for i in range(n):
    size.append(int(input()))
if len(size) == 1:
    print('1')
else:
    size = sorted(size)
    left=0
    leftCur = 0
    right=int(n/2)
    rightCur = right
    res = 0
    while leftCur<right and rightCur<n:
        leftVal = size[leftCur]; rightVal = size[rightCur];
        if leftVal*2 <= rightVal:
            res+=1
            leftCur+=1; rightCur+=1
        else:
            rightCur+=1
    print(n-res)
# else:
#     size = sorted(size)
#     total = len(size)
#     max = size[-1]
#     left = -1
#     cur = 0
#     right = -1
#     res = 0
#     canMatch = False
#     for i in range(len(size)):
#         if size[i]*2 > max:
#             left=i
#             right=i-1
#             canMatch = True
#             break
#     if canMatch == False:
#         print(total)
#     else:
#         while left<=n-1 and cur<=right:
#             if size[cur]*2 <= size[left]:
#                 res+=1
#                 left+=1
#                 cur+=1
#             else:
#                 left+=1
#         print(total-res)
