




"""
t = int(input())
for i in range(t):
    n,m = list(map(int, input().split()))
    big,small = [m]*(n+5), [m]*(n+5)
    last = [0,0,0]
    ans = True
    for c in range(n):
        t,l,h = list(map(int, input().split()))
        dt = t-last[0]
        #print(t,l,h, big[c], small[c], dt)
        if l > big[c]+dt:
            ans = False
        elif h < small[c]-dt:
            ans = False
        big[c+1] = big[c]
        small[c+1] = small[c]
        big[c+1] += dt
        small[c+1] -= dt
        small[c+1] = max(small[c+1], l)
        big[c+1] = min(big[c+1],h)
        last = [t,l,h]
    print("YES" if ans else "NO")
    #print("\n")
"""




from math import ceil
n,m = list(map(int, input().split()))
nums = list(map(int, input().split()))
nums.sort()
s = 0
print(nums)
best = [0]*(n+1)
for i in range(len(nums)):
    s += nums[i]
    best[i] = s
    if i>=m:
        best[i] += best[i-m]
    print(best[i], end=" ")






















