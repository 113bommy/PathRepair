import sys

EPS = 1e-12

def main():
    n,k,t,u,v,l = map(int, sys.stdin.readline().split())
    carrots = [0] * 10001
    for i in range(n):
        carrots[ int(sys.stdin.readline()) ] = 1

    remain_time  = 0
    carrot_count = 0
    ans = 0
    for i in range(1,l + 1):
        #print("kyori:{}\tremain_time:{}\tcarrot_count:{}\tans:{}".format(i,remain_time,carrot_count,ans))
        # ???????????????????????????????????????
        if carrots[i] == 1:
            carrot_count += 1
        # ?????????????¶?????????????????????????
        if carrot_count > k:
            remain_time = t
            carrot_count -= 1

        if remain_time > 0 + EPS:
            # ????????????????????£???????????¶???
            if remain_time * v >= 1.0:
                ans += 1 / v
                remain_time -= 1 / v
            else:
                if carrot_count > 0:
                    ans += 1 / v
                    carrot_count -= 1
                    remain_time = t - (1 - (remain_time * v)) / v
                else:
                    ans += remain_time
                    ans += (1 - (remain_time * v)) / u
                    remain_time = 0
        else:
            remain_time = 0
            # ????????????????????£???????????¶???
            if carrot_count > 0:
                ans += 1 / v
                carrot_count -= 1
                remain_time = t - 1 / v
            else:
                ans += 1 / u

    print("{:.9f}".format(ans))



if __name__ == '__main__':
    main()