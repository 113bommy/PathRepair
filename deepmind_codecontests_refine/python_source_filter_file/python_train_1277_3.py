from math import gcd
def run():
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    nums.reverse()
    # if n == 1:
    #     print(nums[0])
    #     return
    visited = [1] + [0] * (n-1)
    stack = [max(nums)]
    flag = nums[0]
    for i in range(1, n):
        p, m = -1, -1
        for j in range(1, n):
            if visited[j]:
                continue
            t = gcd(flag, nums[j])
            if m != -1 or t > m:
                p = j
                m = t
        stack.append(nums[p])
        flag = m
        visited[p] = 1
    print(" ".join(str(i) for i in stack))    
T = 1
if T:
    for i in range(int(input())):
        run()
else:
    run()
#@Time: 2020/09/08 23:18:59

