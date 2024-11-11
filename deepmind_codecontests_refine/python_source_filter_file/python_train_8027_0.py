n, k = map(int, input().split())
s = [int(x) for x in input().split()]
su = sum(s)
flag = 0
if(su%k != 0):
    print('No')
else:
    v = su // k
    s1 = []
    a = 0
    cou = 0
    for i in range(n):
        cou += 1
        a += s[i]
        if(a > v):
            print('No')
            flag = 1
            break
        elif(a < v):
            continue

        elif(a == v):
            a = 0
            s1.append(cou)
            cou = 0

    if(a != 0):
        s1.append((su) // v)
    if(flag==1):
        print("Yes")
        print(*s1)