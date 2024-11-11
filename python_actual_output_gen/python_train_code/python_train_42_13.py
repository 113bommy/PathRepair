n = int(input())
s = list(map(int, input().split(' ')))
k = max(s)
while 2 * sum(s) > k * n:
    k+=1
print(k)
