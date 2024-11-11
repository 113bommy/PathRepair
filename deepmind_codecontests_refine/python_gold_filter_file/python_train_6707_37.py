def sjs():
    str1 = input()
    # str1 = 'nineteenineteen'
    n = 0
    resoult = {}
    for i in str1:
        resoult[i] = str1.count(i)
    # print(resoult)
    try:

        for i in range(resoult['i']):
            if n == 0:
                if resoult['n'] >= 3 and resoult['i'] >= 1 and resoult['e'] >= 3 and resoult['t'] >= 1:
                    resoult['n'] = resoult['n'] - 3
                    resoult['i'] = resoult['i'] - 1
                    resoult['e'] = resoult['e'] - 3
                    resoult['t'] = resoult['t'] - 1
                    n = n + 1
                else:
                    break
            else:
                if resoult['n'] >= 2 and resoult['i'] >= 1 and resoult['e'] >= 3 and resoult['t'] >= 1:
                    resoult['n'] = resoult['n'] - 2
                    resoult['i'] = resoult['i'] - 1
                    resoult['e'] = resoult['e'] - 3
                    resoult['t'] = resoult['t'] - 1
                    n = n + 1
                else:
                    break
        # for i in range(0,len(str1),15):
        #     if str1[i:i+15] == 'nineteenineteen':
        #         n = n + 1
        print(n)
    except:
        print(0)
sjs()