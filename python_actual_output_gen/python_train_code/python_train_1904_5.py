import sys
input = sys.stdin.readline
m = int(input())
ans = 0
sum_num = 0
c_sum = 0
for i in range(m):
    d,c = map(int, input().split())
    sum_num += d*c
    c_sum += c
#合計に対して、9減らす行為が何回出来るか
print(c_sum-1 + (sum_num//9))