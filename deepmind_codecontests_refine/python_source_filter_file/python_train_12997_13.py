import heapq

n = int(input())
a = list(map(int, input().split()))



red = a[:n]
sr = sum(red)
sum_red = {n: sr}
heapq.heapify(red)
# print(red)

blue = [-1 * i for i in a[2*n:]]
sb = sum(blue)
sum_blue = {2 * n: sb}
heapq.heapify(blue)
# print(blue)

for k in range(n, 2 * n):
    popped_red = heapq.heappushpop(red, a[k])
    sr += a[k] - popped_red
    sum_red[k + 1] = sr
    # print(popped_red, red, sr, sum_red)

for k in range(2 * n - 1, n - 1, -1):
    popped_blue = heapq.heappushpop(blue, -1  * a[k])
    sb += -1 * a[k] - popped_blue
    sum_blue[k] = sb
    # print(popped_blue, blue, sb, sum_blue)

ans = -1 * float('inf')
for k in range(n + 1, 2 * n + 1):
    ans = max(ans, sum_red[k] + sum_blue[k])
    

print(ans)

    
