t = int(input())

for tc in range(t):

    n, k = map(int, input().split())

    arr = [int(z) for z in input().split()]

    left = max(0, n - (2*k))

    res = -10**18

    for i in range(left-1, n):
        for j in range(i+1, n):
            r = (i+1) * (j+1) - (k * (arr[i] | arr[j]))

            res = max(res, r)

    print(res)

    # less = []; more = []
    # for i in range(n):
    #
    #     if arr[i] < i+1:
    #         less.append(i)
    #     else:
    #         more.append([arr[i], i])
    #
    # more1 = []
    # more.sort()
    # for i in more:
    #     more1.append(i[1])
    #
    # less1 = less[::-1]
    # comb = less1 + more1
    #
    # m1 = comb[0]
    #
    #
    # res = -10**18
    #
    # for i in range(1, len(comb)):
    #     m2 = comb[i]
    #     res = max(res, ((m1+1) * (m2+1) - (k * (arr[m1] | arr[m2]))))
    #
    # print(res)
    #
    # # arr2 = sorted(arr)
    # #
    # # m1 = arr2[0]; m2 = arr2[1]
    # #
    # # for i in reversed(range(n)):
    # #     if arr[i] == m1:
    # #         m1d = i+1
    # #         break
    # #
    # # for i in reversed(range(n)):
    # #     if arr[i] == m2 and i+1 != m1d:
    # #         m2d = i+1
    # #         break
    # #
    # # print(m1d * m2d - k * (m1 | m2))
    #
    # # arr1 = []
    # # for i in range(n):
    # #     arr1.append([i, i - arr[i] + 1, arr[i]])
    # #
    # # arr1.sort()
    # #
    # # a, b, c = map(int, arr1[-1])
    # # d, e, f = map(int, arr1[-2])
    # #
    # # print(arr1)
    # #
    # print(a * d - (k * (c | f)))