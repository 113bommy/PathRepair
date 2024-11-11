import math

if __name__ == "__main__":
    n, m = list(map(int, input().split(' ')))
    a = list(map(int, input().split(' ')))
    ax = []
    # code your algorithm here
    otrs = sorted([[nc, nc, nc] for nc in a], key=lambda x: x[1])
    mp = 0
    r = 0
    while mp < m:
        otrs_r = []
        l_used = 0
        for i in range(len(otrs)):
            if mp >= m:
                break
            used = False
            if i == 0 or otrs[i - 1][2] < otrs[i][0] - 1:
                otrs[i][0] -= 1
                r += abs(otrs[i][1] - otrs[i][0])
                mp += 1
                ax.append(otrs[i][0])
                if mp == m:
                    break
                used = True
            if i == len(otrs) - 1 or otrs[i][2] + 1 < otrs[i + 1][0]:
                otrs[i][2] += 1
                r += abs(otrs[i][2] - otrs[i][1])
                mp += 1
                used = True
                ax.append(otrs[i][2])
                if mp == m:
                    break
            if used:
                otrs_r += [otrs[i]]
                l_used = i
            else:
                otrs[l_used][2] = otrs[i][0]

        otrs = otrs_r
    print(r)
    for i in range(m):
        print(ax[i], end=' ')
    print()
