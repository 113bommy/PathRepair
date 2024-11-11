import sys
a = list(map(int,list(input())))
n = len(a)
su = sum(a)
l1 = [i for i in range(n) if a[i] % 3 == 1]
l2 = [i for i in range(n) if a[i] % 3 == 2]

def erase_leading_zeroes(li):
    i = 0
    while i < n:
        if len(li) <= 1:
            return
        if li[i] == 0:
            li.pop(i)
        else:
            return

if su % 3 == 1:
    tmp1 = a[:]
    tmp2 = a[:]
    if len(l1) >= 1:
        tmp1.pop(l1[-1])
        erase_leading_zeroes(tmp1)
    if len(l2) >= 2:
        tmp2.pop(l2[-1])
        tmp2.pop(l2[-2])
        erase_leading_zeroes(tmp2)

    if sum(tmp1) % 3 == 0 or sum(tmp2) % 3 == 0:
        if sum(tmp1) % 3 == 0:
            a = tmp1
        if sum(tmp2) % 3 == 0 and (sum(tmp1) % 3 != 0 or len(tmp2) > len(tmp1)):
            a = tmp2
    else:
        print(-1)
        sys.exit()

elif su % 3 == 2:
    tmp1 = a[:]
    tmp2 = a[:]
    if len(l2) >= 1:
        tmp1.pop(l2[-1])
        erase_leading_zeroes(tmp1)
    elif len(l1) >= 2:
        tmp2.pop(l1[-1])
        tmp2.pop(l1[-2])
        erase_leading_zeroes(tmp2)

    if sum(tmp1) % 3 == 0 or sum(tmp2) % 3 == 0:
        if sum(tmp1) % 3 == 0:
            a = tmp1
        if sum(tmp2) % 3 == 0 and (sum(tmp1) % 3 != 0 or len(tmp2) > len(tmp1)):
            a = tmp2
    else:
        print(-1)
        sys.exit()

if len(a) >= 1:
    print(''.join(map(str,a)))
else:
    print(-1)
