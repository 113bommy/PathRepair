def f(s1, s2):
    return sum(0 if ch1 == ch2 else 1 for ch1, ch2 in zip(s1, s2))


def choose_different(ch1, ch2):
    if ch1 != 'a' and ch2 != 'a':
        return 'a'
    if ch1 != 'b' and ch2 != 'b':
        return 'b'
    return 'c'


def calc_s3(s1, s2, in_match, out_match):
    l3 = []
    in_match_taken = 0
    out_match_taken_1 = 0
    out_match_taken_2 = 0
    for ch1, ch2 in zip(s1, s2):
        if ch1 == ch2:
            if in_match_taken < in_match:
                ch3 = ch1
                in_match_taken += 1
            else:
                ch3 = choose_different(ch1, ch2)
        else:
            if out_match_taken_1 < out_match:
                ch3 = ch1
                out_match_taken_1 += 1
            elif out_match_taken_2 < out_match:
                ch3 = ch2
                out_match_taken_2 += 1
            else:
                ch3 = choose_different(ch1, ch2)

        l3.append(ch3)

    return ''.join(l3)


def main():
    n, t = [int(t) for t in input().split()]
    s1 = input()
    s2 = input()

    dif_12 = f(s1, s2)
    match_12 = n - dif_12
    highest_match = match_12 + dif_12 // 2

    match_require = n - t

    if match_require > highest_match:
        print(-1)
        return
    if match_12 >= match_require:
        in_match = match_require
        out_match = 0
    else:
        in_match = match_12
        out_match = match_require - match_12

    s3 = calc_s3(s1, s2, in_match, out_match)
    print(s3)


if __name__ == '__main__':
    main()
