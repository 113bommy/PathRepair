#https://codeforces.com/contest/252/problem/C


def lower_bound(lst, low, upp, target):
    while upp - low > 1:
        mid = (upp + low) // 2
        if lst[mid] > target:
            upp = mid - 1
        elif lst[mid] < target:
            low = mid
        else:
            return mid
    return low

def main():
    n, d = [int(i) for i in input().split()]
    xx = [int(i) for i in input().split()]

    if n < 3:
        print(0)
        return
    total_num = 0
    for i in range(n-2):
        lth = lower_bound(xx, i, n, xx[i] + d)-i
        num = lth*(lth-1)/2 # combination,3 out of length. C(n,r) r=3
        total_num += num
    print(int(total_num))

main()

