# def sump(v,s,e):
#     a = 0
#     for i in range(s,e,1):
#         a += v[i]
#     return a


def main():
    n,k=map(int,input().split())
    v = list(map(int, input().split()))
    # if sum(v) % k != 0:
    #     print("No")
    #     return

    d = sum(v) / k
    j = 0
    res = ''
    sumpart = 0
    for i in range(len(v)):
        # print("j: %d" % j)
        # print("i: %d" % i)
        # print(sump(v,j,i))
        sumpart += v[i]
        if sumpart == d:
            res += str(i+1) + ' '
            j = i + 1
            sumpart = 0
            if j >= len(v):
                break
        elif sumpart > d:
            print("No")
            return
    res.rstrip()
    print('Yes')
    print(res)


if __name__ == '__main__':
   # while 1:
        main()