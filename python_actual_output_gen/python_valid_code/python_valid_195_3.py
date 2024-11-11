import sys
input = sys.stdin.readline

'''

'''

n = int(input())
r = list(map(int, input().split()))
prefix_sum = [r[0]]
for i in range(1, n):
    prefix_sum.append(prefix_sum[-1] + r[i])

best = 0
done = False
for length in reversed(range(1,n)):
    treshold = 100*length
    for i in range(n-length+1):
        pre = 0 if i == 0 else prefix_sum[i-1]
        total = prefix_sum[i+length-1] - pre
        
        if total >= treshold:
            done = True
            best = length
            break
    if done:
        break

print(best)
