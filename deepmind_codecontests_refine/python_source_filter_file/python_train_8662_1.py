def answer(A, odd, even):
    odds = []
    evens = []
    waseven = 1
    wasodd = 1
    waszero = -1
    ans = 0
    for i in range(len(A)):
        if A[i] and not A[i] % 2:
            if waszero >= 0 and waseven:
                odds.append((i - waszero))
                waszero = -1
            elif waszero >= 0 and wasodd:
                ans += 1
                waszero = -1
            waseven = 1
            wasodd = 0
        elif A[i]:
            if waszero >= 0 and wasodd:
                odds.append((i - waszero))
                waszero = -1
            elif waszero >= 0 and waseven:
                ans += 1
                waszero = -1
            wasodd = 1
            waseven = 0
        else:
            if waszero == -1:
                waszero = i
    odds.sort()
    evens.sort()
    ans += 2 * len(odds) + 2 * len(evens)
    for el in odds:
        if odd >= el:
            odd -= el
            ans -= 2
        else:
            break
    for el in evens:
        if even >= el:
            even -= el
            ans -= 2
        else:
            break
    for i in range(len(A) - 1):
        if A[i] and A[i + 1] and A[i] % 2 != A[i + 1] % 2:
            ans += 1
    return ans


n = int(input())
A = list(map(int, input().split()))
odd = n // 2 + n % 2
even = n // 2
for i in range(n):
    if not A[i] % 2 and A[i]:
        even -= 1
    elif A[i]:
        odd -= 1
print(min(answer([1] + A + [1], odd, even), answer([1] + A + [2], odd, even), answer([2] + A + [1], odd, even), answer([2] + A + [2], odd, even)))
