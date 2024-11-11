#import sys
#input = sys.stdin.readline
 
n = int(input())
a =[int(i) for i in input().split()]
b =[int(i) for i in input().split()]
 
cnt, prev_cnt = 0, -1
while cnt != prev_cnt:
    prev_cnt = cnt
    for i in range(n):
        
        adj_sum = b[i - 1] + b[(i + 1) % n]
        k = (b[i] - a[i]) // adj_sum
        if k > 0:
            b[i] -= k * adj_sum
            cnt += k
 
print(cnt if a == b else -1)