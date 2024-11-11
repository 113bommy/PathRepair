n, p, w, d = [int(x) for x in input().split()]
flag = 0
for i in range(d+1):
    if (p-i*d)%w == 0 and (p-i*d) >= 0:
        win = (p-i*d)//w
        if win+i <= n:
            print (win, i, n-i-win)
            flag = 1
            break
if not flag: print(-1)