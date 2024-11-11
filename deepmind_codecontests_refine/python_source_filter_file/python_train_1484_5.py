
import math

def prime(n):
    factor = {}
    tmp = int(math.sqrt(n)) + 1
    for num in range(2, tmp):
        while n % num == 0:
            n //= num
            if not num in factor.keys():
                factor[num] = 1
            else:
                factor[num] += 1
        if num > n:
            break
    if n != 1:
        if not n in factor.keys():
            factor[n] = 1
        else:
            factor[n] += 1
    return factor


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    dic = {}
    for a in A:
        fac = prime(a)
        for num, c in fac.items():
            if num in dic:
                dic[num].append(c)
            else:
                dic[num] = [c]

    ans = 1
    for num, List in dic.items():
        if len(List) < N-2:
            continue
        else:
            List.sort()
            if len(List) == N-1:
                ans *= num**List[0]
            else:
                ans *= num**(List[1])

    print(ans)

if __name__ == "__main__":
    main()