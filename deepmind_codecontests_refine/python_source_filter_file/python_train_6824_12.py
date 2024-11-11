def solution(c):
    max_s = sum(c)
    ans_rotated = c[0]
    ans_still = 0
    cur = input()
    cur_rev = cur[::-1]
    for k in range(1, N):
        nxt = input()
        nxt_rev = nxt[::-1]

        if nxt < cur and nxt < cur_rev:
            tmp_ans_still = max_s
        else:
            if nxt >= cur and nxt >= cur_rev:
                tmp_ans_still = min(ans_still, ans_rotated)
            elif nxt >= cur:
                tmp_ans_still = ans_still
            elif nxt >= cur_rev:
                tmp_ans_still = ans_rotated

        if nxt_rev < cur and nxt_rev < cur_rev:
            tmp_ans_rotated = max_s
        else:
            if nxt_rev >= cur and nxt_rev >= cur_rev:
                tmp_ans_rotated = min(ans_still, ans_rotated) + c[k]
            elif nxt_rev >= cur:
                tmp_ans_rotated = ans_still + c[k]
            elif nxt_rev >= cur_rev:
                tmp_ans_rotated = ans_rotated + c[k]

        if tmp_ans_still >= max_s and tmp_ans_rotated >= max_s:
            return -1
        ans_still, ans_rotated = tmp_ans_still, tmp_ans_rotated
        cur, cur_rev = nxt, nxt_rev

    return min(ans_still, ans_rotated)

N = int(input())
c = list(map(int, input().split()))

print(solution(c))