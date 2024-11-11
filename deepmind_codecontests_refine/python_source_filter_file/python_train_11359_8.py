import math

n = int(input())
pa = map(int, input().split())
rem, fee = map(int, input().split())

count = 0
for wallet in pa:
    count += math.ceil((wallet - rem)/(rem+fee))

print(count)