#n = int(input())
n, m, k = map(int, input().split())
#s = input()
c = list(map(int, input().split()))
l = 0
for i in range(n):
    if c[i] == 1:
        if m > 0:
            m -= 1
        else:
            l += 1
    else:
        if k > 0:
            k -= 1
        else:
            if m > 0:
                m -= 1
            else:
                l += 1
print(l)