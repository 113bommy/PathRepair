S = input()
cnt = [0]*2019
cnt[0] = 1
n = 0
t = 1
for i in reversed(S):
    n += i*t
    n %= 2019
    cnt[n] += 1
    t *= 10
    t %= 2019
print(sum(i*(i-1)//2 for i in cnt))