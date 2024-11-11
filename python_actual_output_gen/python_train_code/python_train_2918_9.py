s = input()
s1 = s.split()
n1 = int(s1[0])
n2 = int(s1[1])
if n1 > n2:
    l = n1 - n2
    m = l // 2
    print(n2, m)
elif n2 > n1:
    l = n2 - n1
    m = l // 2
    print(n1, m)
else:
    print(n1)