n = int(input())
alist = list(map(int,input().split()))
t = 1
maxt = 1

for i in range(n-1):
    ai = alist[i]
    aiplus1 = alist[i+1]
    if ai <= aiplus1:
        t = t + 1
        if maxt <= t:
            maxt = t
    else:
        t = 1
        if maxt <= t:
            maxt = t

print(t, maxt)
    
