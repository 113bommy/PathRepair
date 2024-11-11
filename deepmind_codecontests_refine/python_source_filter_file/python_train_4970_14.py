def check(x):
    amount = n
    s = 0
    while amount > 0:
        amount -= x
        s += x
        if amount < 0:
            s -= abs(amount)
            break
        amount -= (amount // 10)
 #   print(x, s)
    if s >= (n - s):
        return True
    else:
        return False

def binarysearch(p, q):
    if q - p <= 1:
        print(p)
        return
    mid = (p + q) // 2
 #   print(p, q, mid, check(mid))
    if check(mid):
        binarysearch(p, mid - 1)
    else:
        binarysearch(mid + 1, q)


n = int(input())
binarysearch(1, n // 2 + 1)
