n = int(input())
ans = 0
m = 1
while n>0:
    k = n%10
    n = n/10
    if k == 4:
        ans = ans + m * 1
    elif k == 7:
        ans = ans + m * 2
    m = m * 2
print (ans)