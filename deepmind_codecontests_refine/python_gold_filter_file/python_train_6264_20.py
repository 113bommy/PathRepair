n = int(input())
a = list(map(int, input().split()))
#a = [k for k in range(200000)]
m = max(a)
k = a.index(m)
l = k
r = k + 1
flag = True
while (l > 0) + (r < n):
#    print('lol')
    if l == 0:
        if r == n:
            flag = True
            break
        elif a[r] < m:
            m = a[r]
            r += 1
        else:
            flag = False
    #        print('lol')
            break
    elif r == n:
        if a[l - 1] < m:
            l -= 1
            m = a[l]
        else:
            flag = False
            break
    else:
        if a[l - 1] > a[r]:
            if a[l - 1] >= m:
                flag = False
                break
            else:
                l -= 1
                m = a[l]
        else:
            if a[r] >= m:
                flag = False
                break
            else:
                m = a[r]
                r += 1

#print(l, r, m)
if flag:
    print('yes')
else:
    print('no')
    