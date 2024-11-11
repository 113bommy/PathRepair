import sys

def input(): return sys.stdin.readline().rstrip("\r\n")

def maps(): return [int(i) for i in input().split()]


def isprime(num):
    if num > 1:

        # Iterate from 2 to n / 2
        for i in range(2, int(num / 2) + 1):

            # If num is divisible by any number between
            # 2 and n / 2, it is not prime
            if (num % i) == 0:
                return True
        else:
            return False

    else:
        return False


from collections import defaultdict

for _ in range(*maps()):
    k, = maps()
    num = input()
    if '1' in num:
        print(1, 1, sep='\n')
        continue
    A = []
    for i in range(1, 100):
        if isprime(i):
            A.append(i)
        # else:
        #     print(i)

    # print(len(A))

    d = defaultdict(int)
    for i in num:
        d[i] += 1

    # A.sort(key=lambda x: len(str(x)))

    for i in A:
        i = str(i)
        if len(i) == 2:
            d[i[0]] -= 1
            d[i[1]] -= 1

            if d[i[0]] >= 0 and d[i[1]] >= 0:
                idx1 = num.index(i[0])
                idx2 = k - num[::-1].index(i[1]) - 1
                if idx1 < idx2:
                    print(len(i), i, sep='\n')
                    break

            d[i[0]] += 1
            d[i[1]] += 1

        elif len(i) == 1:
            d[i[0]] -= 1
            if d[i[0]] >= 0:
                print(1, i, sep='\n')
                break
            d[i[0]] += 1

    else:
        print(-1)


# arr2 = ["23", "53", "37", "73"]
# print(7 not in arr2)
