n = int(input())
a = [int(x) for x in input().split()]
res = ['A']*n
cnt = [0]*101
for i in a:
    cnt[i] += 1
good_num = cnt.count(1)
bad_above_2 = False
for i in range(101):
    if cnt[i] > 2:
        bad_above_2 = True
        break
        
if good_num%2 == 0 or bad_above_2 > 0:
    print('YES')
    to_b = False

    for i in range(n):
        if cnt[a[i]] == 1:
            if to_b:
                res[i] = 'B'
            to_b = not to_b
            
    if good_num%2 != 0:
        for i in range(n):
            if cnt[a[i]] > 2:
                res[i] = 'B'
                break
    print(res)
else:
    print('NO')
