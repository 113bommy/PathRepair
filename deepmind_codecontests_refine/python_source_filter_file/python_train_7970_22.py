n,k = map(int,input().split())
i = 0
t = 0
while 240 - k - (t + 5 * i) > 4 and n < 0:
    i += 1
    t = t + 5 * i
print(i)