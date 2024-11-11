def get_r_list(a, b, m):
    k = 2
    two_power_k = 1
    isMatch = False

    if a == b:
        return 1, []

    while True:
        if b <= two_power_k * (a + 1):
            isMatch = True
            break

        if k == 50:
            break


        k += 1
        two_power_k *= 2

    isDone = False

    if isMatch and b < two_power_k * (a + 1):
        k -= 1
        two_power_k = two_power_k / 2


    gap = b - two_power_k * (a + 1)

    two_power_k = int(two_power_k / 2) # 2^k-3
    r_list = []

    if b == two_power_k * (a + 1) * 2:
        isDone = True
        for i in range(1, k - 1):
            r_list.append(0)

    while two_power_k != 0:
        # print("two: ", end="")
        # print(two_power_k)
        if gap >= two_power_k:
            index_r = 0

            gap_divide = int(gap / two_power_k)

            if gap_divide > m - 1:
                index_r = m - 1
            else:
                index_r = gap_divide

            gap = gap - two_power_k * index_r
            r_list.append(index_r)

            two_power_k = int(two_power_k / 2)
        else:
            two_power_k = int(two_power_k / 2)
            r_list.append(0)


    if gap == 0:
        isDone = True
        r_list.append(0)

    else:
        if gap <= m - 1:
            isDone = True
            r_list.append(gap)
        else:
            isDone = False

    if isDone:
        return k, r_list

    else:
        return -1, r_list

    # print(k)
    # print(r_list)


def cute_sequence(a, b, m):
    k, r_list = get_r_list(a, b, m)

    if k == -1:
        print(k)
        return

    if k == 1:
        print(1, end=" ")
        print(b)
        return

    sequence_list = []
    sequence_list.append(a)

    sequence_list.append(a + r_list[0] + 1)

    for i in range(2, k):
        next_a = 2 * sequence_list[i - 1] + r_list[i - 1] - r_list[i - 2]
        sequence_list.append(next_a)
    print(k, end=" ")

    for ele in sequence_list:
        print(ele, end=" ")
    print()
    return



N = int(input())
for _ in range(N):
    a, b, m = input().split()
    a = int(a)
    b = int(b)
    m = int(m)
    cute_sequence(a, b, m)


