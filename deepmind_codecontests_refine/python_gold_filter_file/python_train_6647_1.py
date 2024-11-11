import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)

def getN():
    return int(input())
def getList():
    return list(map(int, input().split()))
import math

n = getN()
nums = getList()
if sum(nums) % ((n * (n+1)) // 2) != 0:
    print("NO")
    sys.exit()
n_operate = sum(nums) // ((n * (n+1)) // 2)

v_valid = n_operate
v_sign = n

for i, j in zip(nums, nums[1:] + [nums[0]]):
    diff = j - i
    if diff > v_valid:
        print("NO")
        sys.exit()
    if (v_valid - diff) % v_sign != 0:
        print("NO")
        sys.exit()
    n_operate -= (v_valid - diff) // v_sign
    # print(n_operate)
if n_operate == 0:
    print("YES")
else:
    print("NO")
# print("YES")