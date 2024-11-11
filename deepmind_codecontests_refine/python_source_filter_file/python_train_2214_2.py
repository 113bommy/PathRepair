def make_freq_dict(n, a):
    d = {}
    for i in range(n):
        if a[i] not in d:
            d[a[i]] = 1
        else:
            d[a[i]] += 1
    return d

def make_occs_dict(n, a):
    d = {}
    for i in range(n):
        if a[i] not in d:
            d[a[i]] = [i]
        else:
            d[a[i]].append(i)
    return d

def new_freqs(a):
    d = {}
    for i in a:
        d[i] = 0
    return d

def sames_choose_4(num):
    if num < 4:
        return 0
    numerator = num * (num - 1) * (num - 2) * (num - 3)
    denominator = 24
    return numerator // denominator

def solve(n, a):
    total = 0
    og_freqs = make_freq_dict(n, a)
    for k in og_freqs:
        total += sames_choose_4(og_freqs[k])
    for i in range(n - 3):
        freqs = new_freqs(a)
        ai = a[i]
        og_freqs[ai] -= 1
        add_this = 0
        subtotals = {}
        for j in range(i + 1, n - 2):
            aj = a[j]
            if aj == ai:
                total += add_this
            else:
                freqs[aj] += 1
                if aj in subtotals:
                    add_this -= subtotals[aj]
                subtotals[aj] = freqs[aj] * (og_freqs[aj] - freqs[aj])
                add_this += subtotals[aj]
    return total


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve(n, a))
main()