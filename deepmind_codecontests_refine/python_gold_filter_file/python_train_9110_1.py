import sys

input = sys.stdin.readline


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)


def main():
    n, m, s, d = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    curr = 0
    f = 0
    ans = []
    obs = []
    obs.append([a[0], 0])
    j = 0
    for i in range(1, n):
        if a[i] - a[i - 1] -2<s:
            obs[j][1] += a[i] - a[i - 1]
        else:
            obs.append([a[i], 0])
            j += 1
    curr = 0
    # for i in obs:
    #     print(i)
    obs.append([float('inf'), -1])
    i=0
    while(1):
        if obs[i][1] == -1:
            break
        if obs[i][0] - 1 - curr >= s:
            ind = -1
            for j in range(i, len(obs)-1):
                if obs[j][0] - (obs[i][0] - 1) + obs[j][1] + 1 <= d:
                    ind = j
                else:
                    break
            if ind < i:
                print('IMPOSSIBLE')
                return
            else:
                ans.append(['RUN', obs[i][0] - 1 - curr])
                ans.append(['JUMP', obs[ind][0] - (obs[i][0] - 1) + obs[ind][1] + 1])
                curr = obs[ind][0] + obs[ind][1] + 1
                i = ind + 1
        else:
            print('IMPOSSIBLE')
            return
    if m - curr:
        ans.append(['RUN', m - curr])
    for i in ans:
        print(*i)
    return


if __name__ == "__main__":
    main()
