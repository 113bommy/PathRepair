n = input()
a = input()
s = 1
if a.count('0') == len(a):
    s = 0
else:
    prev = a.find('1')
    for i in range(0, len(a), 2):
        if prev != i and a[i] == '1':
            s *= (i-prev) // 2
            prev = i
print (s)
