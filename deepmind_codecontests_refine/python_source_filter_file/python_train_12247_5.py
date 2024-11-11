n, m = map(int, input().split())
s = input()

cur, flag = 0, 0
res, ncur = 0, 0
while ncur < n :
    flag = 0
    cur = ncur
    for i in range(1, m) :
        if cur + i < n and s[cur + i] == '1' : 
            ncur = cur + i
            flag = 1
    if flag == 0 :
        break
    else :
        res += 1
if ncur == n - 1 : 
    print (res)
else : 
    print ("-1")