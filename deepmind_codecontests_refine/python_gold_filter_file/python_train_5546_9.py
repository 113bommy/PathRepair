def mul(arr):
    res = 1
    for e in arr:
        res *= e
    return res


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(x) for x in input().split()]
        res = []
        positive = sorted([e for e in a if e >= 0], reverse=True)
        negative = sorted([e for e in a if e < 0], reverse=False)
        for e in positive:
            if e == 0:
                res.append(0)
                break
        if len(positive) >= 5:
            res.append(mul(positive[:5]))
        if len(negative) >= 5:
            res.append(mul(negative[len(negative) - 5:]))
        for i in range(1, 5):
            if len(negative) >= 5 - i and len(positive) >= i:
                if (5 - i) % 2 == 0:
                    res.append(mul(negative[:5 - i]) * mul(positive[:i]))
                else:
                    res.append(mul(negative[len(negative) - 5 + i:]) * mul(positive[len(positive) - i:]))
        print(max(res))