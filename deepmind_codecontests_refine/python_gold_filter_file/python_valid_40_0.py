def main(n, a, b) -> int:
    pref_a = [0]
    pref_b = [0]

    suf_a = [0]
    suf_b = [0]

    for i in range(n):
        pref_a.append(pref_a[-1] + a[i])
        pref_b.append(pref_b[-1] + b[i])
    pref_a.append(pref_a[-1])
    pref_b.append(pref_b[-1])

    for i in range(n-1, -1, -1):
        suf_a.append(suf_a[-1] + a[i])
        suf_b.append(suf_b[-1] + b[i])
    suf_a.append(suf_a[-1])
    suf_b.append(suf_b[-1])

    suf_a.reverse()
    suf_b.reverse()

    bob_score = float('inf')
    for i in range(1, n+1):
        _alice_score = pref_a[i] + suf_b[i]
        _bob_score = max(pref_b[i-1], suf_a[i+1])
        #print(i, _alice_score, _bob_score)

        if bob_score > _bob_score:
            bob_score = _bob_score

    return bob_score


if __name__ == '__main__':
    t = int(input())
    ans = []
    for i in range(t):
        m = int(input())
        a = [int(i) for i in input().split(" ")]
        b = [int(i) for i in input().split(" ")]
        ans.append(main(m, a, b))

    for i in ans:
        print(i)
