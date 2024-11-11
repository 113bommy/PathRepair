def solve():
    N = len(S)
    for i in range(N):
        for j in range(i, N):
            end = j - (len(T) - 1 - (j - i))
            if end < 0:
                continue
            candidate = S[i: j + 1] + S[end: j][::-1]
            if candidate == T:
                return 'yes'

    return 'no'

# magic.gen_input()
test_cases = int(input())
for test_case in range(test_cases):
    S = input()
    T = input()
    print(solve())