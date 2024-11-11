from collections import Counter

def can_we_give(freq, packets, n):
    fullfilled = 0
    for food_packets in freq.keys():
        fullfilled += freq[food_packets] // packets
    if fullfilled >= n:
        return True
    else:
        return False


def main():
    # Taking input
    n, m = (int(num) for num in input().split())
    A = [int(num) for num in input().split()]
    if m < n:    # Base Case
        return 0
    else:
        freq = Counter(A)    # Frequency of each and every food packets
        # Here l is the minm no.of expedition and r is the
        # maxm no.of expedition
        l, r = 1, max(freq.values())
        while l+1 < r:
            mid = (l+r) // 2
            if can_we_give(freq, mid, n):
                l = mid
            else:
                r = mid

        return l

if __name__ == '__main__':
    output = main()
    print(output)




