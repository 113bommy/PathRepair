from sys import stdin
n = int(stdin.readline().rstrip())
l = list(map(int, stdin.readline().rstrip().split(" ")))
s = l[0]
s1 = (l[0]//2) * 2
l[0]=l[0]%2
for i in range(1,n):

    s += l[i]

    if l[i] != 0:
        l[i] = (l[i] + l[i - 1])
        s1 += (l[i]//2) * 2
    else:
        if l[i-1]==1:
            s1 = 1
            break
    l[i] = (l[i])%2

if l[-1] == 1 or s1 != s:
    print("NO")
else:
    print("YES")

