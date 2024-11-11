import sys

n, m, c = map(int, input().split())
free = n
nums = [0] * n

for i in range(m):
    pi = int(input())
    if(pi > c//2):
        current = n - 1
        while(nums[current] > 0 and nums[current] >= pi and current >= 0):current -= 1
        if(current == -1):current = 0
        if(nums[current] == 0):free -= 1
        nums[current] = pi
        print(current + 1)
    else:
        current = 0
        while(current < n and nums[current] > 0 and nums[current] <= pi):current += 1
        if(current == n):current = n - 1
        if(nums[current] == 0):free -=1
        nums[current] = pi
        print(current + 1)

    if(free == 0):break

