s = input()
n = int(input())
for i in range(n):
    order, a, b, *c = input().split()
    a = int(a)
    b = int(b)
    if order == 'replace':
        s = s[:a] + c[0] + s[b+1:]
    elif order[0] == 'r':
        s = s[:a] + s[::-1][len(s)-b-1:len(s)-a]+ s[b+1:]
    else:
        print(s[a:b+1])
