import math

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def main():
    n = int(input())
    raw = input()
    pk = [int(x) for x in raw.split()]
    # print(pk)
    ans = get_ans(pk)
    print(ans)

def get_ans(arr):
    t = max(arr)
    factors = [0] * (t + 2)
    for i in arr:
        factors[i] = 1

    ans = 0

    for i in range(2, t + 2):
        count = 0
        for k in range(i, t + 2, i):
            count += factors[k]
        if count > ans:
            ans = count
    return ans
if __name__ == '__main__':
    main()
