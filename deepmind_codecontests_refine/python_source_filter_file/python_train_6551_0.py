# Edit: 2014/09/14
# Lang: Python3
# Time: .00s

if __name__ == "__main__":

    n = int(input())
    # print("n:",n)
    hl = []

    for i in range(n):
        hl.append(int(input()))
    # print(hl)

    # hl = [5, 5]
    # hl = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
    # hl = [1,2,3,4,5]
    #hl = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    i = 0
    d = 0
    ans = 1

    sorted(hl,reverse=True)

    for i, h in enumerate(hl):  # return index, value
        #d = i // 4
        a = h - d
        if a < 0:
            a = 0
        ans += a
        if i % 4 == 3:
            d += 1
    print(ans)
    #print(type(ans))