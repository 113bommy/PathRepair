import sys


def read_ints():
    return [int(x) for x in sys.stdin.readline().strip().split()]


def main():
    N = read_ints()[0]
    nums = read_ints()
    
    pref = [0] * N 
    suf = [0] * N

    pref[0] = 1
    ans = 1
    for ix in range(1, N):
        pref[ix] = 1 + (pref[ix - 1] if nums[ix] > nums[ix - 1] else 0)
        ans = max(ans, pref[ix])

    suf[N - 1] = 1
    for ix in range(N - 2, -1, -1):
        suf[ix] = 1 + (suf[ix + 1] if nums[ix] < nums[ix + 1] else 0)
    
    for to_delete in range(1, N - 2):
        if nums[to_delete - 1] < nums[to_delete + 1]:
            ans = max(pref[to_delete - 1] + suf[to_delete + 1], ans)
    print(ans)    


if __name__ == '__main__':
    main()

