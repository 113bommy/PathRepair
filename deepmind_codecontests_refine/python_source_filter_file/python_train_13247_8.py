import sys
import math
input = sys.stdin.readline
 
t = int(input())

a = list(input().rstrip())
b = list(input().rstrip())

print(a)
print(b)

if a.count('1') != b.count('1'):
    print(-1)
else:
    nums = []
    running = 0
    for i in range(len(a)):
        if a[i] == '1':
            running += 1
        if b[i] == '1':
            running -= 1
            
        nums.append(running)
        
    print(max(nums) - min(nums))