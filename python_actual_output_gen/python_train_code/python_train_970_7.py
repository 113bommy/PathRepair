x = int(input())
n,m = list(map(int,input().split()))
s = 0
while (n%10 !=7 and n/10 !=7 and m%10 !=7 and m/10 !=7):
    m -= x
    s += 1
    if m < 0:
        m = 60 -m
        n = n - 1
        if n < 0:
            n = 23
print(s)
