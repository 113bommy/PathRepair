from sys import stdin


def input():
    return stdin.readline()[:-1]


def intput():
    return int(input())


def sinput():
    return input().split()


def intsput():
    return map(int, sinput())


debugging = False
def dprint(*args):
    if debugging:
        print(*args)
    else:
        pass



shift = 100001
# Code
t = intput()
for _ in range(t):
    n, x = intsput()

    s = input()

    balances = [0] * 200002

    b = 0
    for i in range(n):
        if s[i] == '1':
            b -= 1
        else:
            b += 1
        balances[b + shift] += 1

    
    finalb = b
    if finalb == 0 and 0 <= x + shift < len(balances) and balances[x + shift]:
        print(-1)
        continue
    elif finalb == 0:
        print(0)
        continue

    k = x
    ans = 0
    if x == 0:
        ans += 1

    if len(balances) > k + shift >= 0:
        while len(balances) > k + shift >= 0:
            ans += balances[k + shift]
            k -= finalb
        print(ans)
    else:
        if k + shift >= len(balances) and finalb > 0:
            k -= (((k + shift) - len(balances) + 1) // finalb) * finalb
            while k >= len(balances):
                k -= finalb
            while len(balances) > k + shift >= 0:
                ans += balances[k + shift]
                k -= finalb
            print(ans)
        elif k + shift < 0 and finalb < 0:
            k += ((0 - (k + shift)) // (-finalb)) * (-finalb)
            while k + shift < 0:
                k += - finalb
            while len(balances) > k + shift >= 0:
                ans += balances[k + shift]
                k -= finalb
            print(ans)
        else:
            print(0)
