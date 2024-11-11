
MAX_NUM = int(1E4 + 1)

if __name__ == '__main__':
    N = int(input())
    A = [int(i) for i in input().strip().split()]
    sorted_A = sorted(A)
    smallest = sorted_A[0]
    correct_pos = [0] * MAX_NUM
    flag_A = [False] * MAX_NUM
    for i, val in enumerate(sorted_A):
        correct_pos[val] = i

    ans = 0
    for i in range(len(A)):
        if flag_A[i]:
            continue
        next_pos = i
        sum = 0
        m = 1E4
        an = 0
        while True:
            an += 1
            val = A[next_pos]
            sum += val
            m = min([m, val])
            flag_A[A[next_pos]] = True
            next_pos = correct_pos[val]
            if flag_A[A[next_pos]]:
                break
        ans += min([sum + (an - 2) * m, m + sum + (an + 1) * smallest])

    print(ans)