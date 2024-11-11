[n, t] = list(map(int, input().split()))
l = list(map(int, input().split()))

for i in range(n):
    if l[i] < 86400:
        if t-86400+l[i] <= 0 :
            print(i+1)
            break
        else:
            t -= (86400+l[i])

