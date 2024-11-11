from sys import exit
m = int(input())
i = 4
pows = [5**i for i in range(100)]
while 1:
    i += 1
    l = 0
    r = 100
    while l < r:
        cur = (l + r + 1) // 2
        if i % pows[cur] == 0:
            l = cur
        else:
            r = cur - 1
    
    m -= l
    if m == 0: break
    if m < 0:
        print(0)
        exit(0)
print(5)
for j in range(i, i + 5):
    print(j, end=' ')
    
