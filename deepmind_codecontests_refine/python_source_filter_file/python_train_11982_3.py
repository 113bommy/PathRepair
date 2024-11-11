def countc(s, c):
    k = 0
    for x in s:
        if x == c:
            k += 1
    return k

s = input()
n = len(s)
k = countc(s, '1')

if '0' not in s:
    s1 = '1' * k + '2' * (n - k)
elif '2' not in s:
    s1 = '0' * (n - k) + '1' * n
else:
    c = 0
    for i in range(n):
        if s[i] == '0':
            c += 1
        elif s[i] == '2':
            break
    s1 = '0' * c + '1' * k
    for j in range(i, n):
        if s[j] != '1':
            s1 += s[j]
            
    

print(s1)
