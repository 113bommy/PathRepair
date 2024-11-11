from collections import deque


def check(s):
    q = deque()
    q.append(s[0])
    for c in s[1:]:
        if len(q) != 0:
            t = q[-1]
            if t + c == '()':
                q.pop()
            else:
                q.append(c)
        else:
            q.append(c)

    s = set(q)
    if '(' in s and ')' in s:
        return -1, None
    elif '(' in s:
        return len(q), '('
    elif ')' in s:
        return len(q), ')'
    else:
        return 0, None


def main():
    n = int(input())
    left_s = dict()
    right_s = dict()
    c_s_cnt = 0  # the number of complete sequences
    for _ in range(n):
        s = input()
        c, mod_s = check(s)
        if c == 0:
            c_s_cnt += 1
        elif c == -1:
            pass
        else:
            if mod_s == '(':
                if c in left_s:
                    left_s[c] += 1
                else:
                    left_s[c] = 1
            else:
                if c in right_s:
                    right_s[c] += 1
                else:
                    right_s[c] = 1

    ans = c_s_cnt * c_s_cnt
    for k in left_s:
        if k in right_s:
            ans += max(left_s[k], right_s[k])

    print(ans)


if __name__ == '__main__':
    main()
