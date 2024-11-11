#0 1       0 1        0 1
#0 0       0 1        1 0

n = int(input())
a = input()
b = input()

t1 = t2 = t3 = t4 = 0
for i in range(n):
    if (a[i] == b[i] == '0'):
        t1 += 1
    
    if ((a[i] == '1') & (b[i] == '0')):
        t2 += 1

    if (a[i] == b[i] == '1'):
        t3 += 1

    if ((a[i] == '0') & (b[i] == '1')):
        t4 += 1

ans = t1 * t2 + t1 * t3 + t1 * t4

print(ans)