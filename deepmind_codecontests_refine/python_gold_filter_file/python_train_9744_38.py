def alex(a, k):
    current_round = sum(a) / len(a)
    if current_round + 0.5 >= k:
        return 0
    ans = 2 * (k * len(a) - 0.5 * len(a) - sum(a))
    return ans


if __name__ == '__main__':
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    print(int(alex(a, k)))
