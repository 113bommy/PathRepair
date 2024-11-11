n = int(input())
l = list(map(int, input().split()))
dic = {}
li = list(set(l))
a = len(li)
b = max(li)
if b > a:
    print(-1)
else:
    for i in range(a):
        dic[i + 1] = 0
    for i in range(n):
        dic[l[i]] += 1
    ls = []
    for i in range(a):
        s = [i + 1, dic[i + 1]]
        ls.append(s)
    jud = 0
    for i in range(1, a):
        if ls[i][1] > ls[i - 1][1]:
            print(-1)
            jud = 1
            break
    if jud == 0:
        print(a)
        lt = []
        for i in range(n):
            ss = dic[l[i]]
            dic[l[i]] -= 1
            lt.append(str(ss))
        print(' '.join(lt))

