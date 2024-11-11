import sys

def solve():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = [int(a) for a in input().split()]

    n_head_pos = dict() #一番最初にnが出てくるindex
    rem_head_num = [-1] * N #i番目から処理を始めた時に残る数列の先頭の数字
    for i in reversed(range(N)):
        if A[i] not in n_head_pos:
            rem_head_num[i] = A[i]
        else:
            if n_head_pos[A[i]] == N-1: rem_head_num[i] = -1
            else: rem_head_num[i] = rem_head_num[n_head_pos[A[i]] + 1]
        n_head_pos[A[i]] = i
    #print(n_head_pos)
    #print(rem_head_num)

    start_cycle = [] #先頭の数字の周期
    start = -1
    used = set()
    while start not in used:
        used |= {start}
        start_cycle.append(start)
        if start == -1: next = rem_head_num[0]
        elif n_head_pos[start] < N - 1: next = rem_head_num[n_head_pos[start] + 1]
        else: next = -1
        start = next

    #print(start_cycle)

    len_cycle = len(start_cycle)
    last = (K - 1) % len_cycle 
    #print(last)
    if start_cycle[last] == -1: start_index = 0
    elif n_head_pos[start_cycle[last]] < N - 1: start_index =n_head_pos[start_cycle[last]] + 1
    else: start_index == -1
    #print(start_index)
    if start_index > 0:
        out = []
        using = dict()
        l = 0
        for i in range(start_index, N):
            if A[i] in using:
                aindex = using[A[i]]
                l = aindex
                for a in out[aindex:]:
                    using.pop(a)
                out = out[:aindex]
            else:
                out.append(A[i])
                using[A[i]] = l
                l += 1
                #print(out, using, l)
        print(" ".join(map(str, out)))
    else: print(" ")

    return 0

if __name__ == "__main__":
    solve()