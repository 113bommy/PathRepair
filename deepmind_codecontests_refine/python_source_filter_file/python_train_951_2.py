n = int(input())
a = list(map(int, input().split()))
sp = [0]
s = ''
l = 0
r = n - 1
while r - l != -1:
    if a[l] == a[r] and l != r:
        sp1 = sp.copy()
        s1 = s
        while sp[-1] < a[l]:
            sp.append(a[l])
            l += 1
            s += 'L'
        while sp1[-1] < a[r]:
            sp1.append(a[r])
            r -= 1
            s1 += 'R'
        if len(sp) > len(sp1):
            print(len(sp) - 1)
            print(s)
        else:
            print(len(sp1) - 1)
            print(s1)
        exit(0)
    if a[l] > sp[-1] and a[r] < sp[-1]:
        sp.append(a[l])
        l += 1
        s += 'L'
    elif a[r] > sp[-1] and a[l] < sp[-1]:
        sp.append(a[r])
        r -= 1
        s += 'R'
    elif a[l] > sp[-1] and a[r] > sp[-1]:
        if a[l] < a[r]:
            sp.append(a[l])
            l += 1
            s += 'L'
        else:
            sp.append(a[r])
            r -= 1
            s += 'R'
    else:
        break
print(len(sp) - 1)
print(s)