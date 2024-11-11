inp = input().split(' ')
ts = int(inp[0])
tf = int(inp[1])
T = int(inp[2])
inp = input()
n = int(inp)

if n == 0:
    print(ts)

else:
    inp = input().split(' ')
    min_del_t = 10000000000;
    ans = int(inp[0])-1
    t_cur = ts
    for tS in inp:
        t = int(tS)
        time_waiting = t_cur-t+1
        if t_cur < t and t_cur+T<=tf:
            ans = t_cur
            break
        else:
            if min_del_t > time_waiting and t_cur+T <= tf:
                min_del_t = time_waiting
                ans = t-1
        t_cur += T
    #print(min_del_t)
    if(t_cur+T<=tf):
        print(t_cur)
    else:
        print(ans)

