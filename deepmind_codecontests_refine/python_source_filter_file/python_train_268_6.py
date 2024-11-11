

def find_max(n, k, m, ts):
    out = 0

    ts.sort()

    for i in range(n): # first i tasks solved completely
        cur = 0

        time = sum(ts) * i
        if time > m:
            break
        else:
            cur += (k + 1) * i

        time_left = m - time
        cur_subtask = 0
        while time_left > 0 and cur_subtask < k:
            solved = min(n - i, time_left // ts[cur_subtask])

            if solved == 0:
                break

            time_left -= solved * ts[cur_subtask]
            cur += solved
            cur_subtask += 1

        out = max(out, cur)

    return out


def main():
    n, k, m = (int(x) for x in input().split())
    ts = [int(x) for x in input().split()]

    print(find_max(n, k, m, ts))


if __name__ == "__main__":
    main()


