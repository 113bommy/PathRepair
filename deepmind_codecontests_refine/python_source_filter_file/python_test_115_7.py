t = int(input())
for j in range(t):
    s = input().split()
    n = int(s[0])
    h = int(s[1])
    s = input().split()
    a = []
    count = n
    for i in range(1,n):
        a.append(int(s[i])-int(s[i-1]))
    a.append(h)
    if h%n == 0:
        k = h//n
    else:
        k = h//n+1
    s.sort()
    for i in range(n):
        if a[i]>=k:
            print(k)
            break
        else:
            h = h - a[i]
            count -= 1
            if h%count == 0:
                k = h//count
            else:
                k = h//count+1
    