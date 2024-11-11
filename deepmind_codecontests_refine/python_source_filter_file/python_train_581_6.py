m = list(map(int, input()))
ans = 0
if sum(m[:3]) > sum(m[3:]):
    m = m[3:] + m[:3]
while sum(m[:3]) != sum(m[3:]):  
    ans += 1
    minsum1 = 10
    maxsum2 = 0
    mini = -1 #min's i
    maxi = -1 #max's i
    for i in range(3):
        if m[i] < minsum1:
            minsum1 = m[i]
            mini = i
    for i in range(3, 6):
        if m[i] > maxsum2:
            maxsum2 = m[i]
            maxi = i
    var1 = m[0:6]
    var1[mini] = sum(var1[3:]) - sum(var1[:3]) + minsum1
    if var1[mini] > 9:
        var1[mini] = 9
#    print(m, end = '===')
    var2 = m[0:6]
    var2[maxi] = maxsum2 - (sum(var2[3:]) - sum(var2[:3]))
    if var2[maxi] < 1:
        var2[maxi] = 1
#    print(var1, var2, ans, end=' ')
    if sum(var1[3:]) - sum(var1[:3]) < sum(var2[3:]) - sum(var2[:3]):
        m = var1
    else:
        m = var2
#    print(m)
print(ans)