n = int(input()) 
#n, m = map(int, input().split()) 
s = input()
#c = list(map(int, input().split()))
a = []
for i in range(n):
    if s[i] == '4':
        a.append(2)
        a.append(3)
        a.append(2)
    elif s[i] == '6':
        a.append(5)
        a.append(4)
    elif s[i] == '8':
        a.append(7)
        a.append(2)
        a.append(2)
        a.append(2)
    elif s[i] == '9':
        a.append(7)
        a.append(3)
        a.append(3)
        a.append(2)
    elif int(s[i]) > 1:
        a.append(int(s[i]))
a.sort()
for i in range(len(a) - 1, -1, -1):
    print(a[i], end = '')
        