S = input()


def solve(S):
    buf = [1] * len(S)

    for i in range(len(buf) - 2):
        if S[i:i+2] == "RR":
            buf[i+2] += buf[i]
            buf[i] = 0

    for i in range(len(buf) - 1, 1, -1):
        if S[i-1:+1] == "LL":
            buf[i-2] += buf[i]
            buf[i] = 0

    return " ".join(map(str, buf))


print(solve(S))
