i = 0
n = int(input())
maxR = -10**9
minR = int(input())
while i < n:
    R = int(input())
    maxR = max(maxR, R-minR)
    minR = min(minR, R)
    i += 1
print(maxR)