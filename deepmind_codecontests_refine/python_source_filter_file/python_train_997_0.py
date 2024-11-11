def souvenier_calc(max_weight, weights, value):
    const = len(weights)
    ans = [-1061109567 for x in range(max_weight+1)]
    node = [(x, y) for x, y in zip(weights, value)]
    node = sorted(node, key=lambda x: x[1]//x[0], reverse=True)
    weights = [x[0] for x in node]
    value = [x[1] for x in node]
    sum = 0
    sol = 0
    ans[0] = 0
    for i in range(const):
        sum += weights[i]
        if sum > max_weight:
            sum = max_weight
        down = max(weights[i], sum-3)
        for weight in range(sum, down-1, -1):
            ans[weight] = max(ans[weight], ans[weight-weights[i]]+value[i])
            sol = max(sol, ans[weight])

    return sol

if __name__ == '__main__':
    N, M = map(int, input().split())
    assert(N <= 10**5 and M <= 3*(10**5)), 'Out of range'
    weights = []
    value = []
    for i in range(N):
        x, y = map(int, input().split())
        assert(x >= 1 and x <= 3), 'Out of range'
        assert(y >= 1 and y <= 10**9), 'Out of range'
        weights.append(x)
        value.append(y)
    print(souvenier_calc(M, weights, value))
