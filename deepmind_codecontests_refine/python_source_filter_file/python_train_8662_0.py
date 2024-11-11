import sys

input = lambda: sys.stdin.readline()

# n,k = map(int,input().split())
n = int(input())
if n == 1:
    print(0)
    exit(0)
a = list(map(int, input().split()))
t = -1
o, e = 0, 0
for i in a:
    if i != 0:
        e += (i + 1) % 2
        o += i % 2
ans = 0
for j in range(n - 1):
    if a[j] != 0 and a[j + 1] != 0:
        ans += int(a[j] % 2 != a[j + 1] % 2)

e = n // 2 - e
o = n // 2 + n % 2 - o
# print(e, o)
l = -1
f = False
#    0e,0o,eo,ee,oo
z = [[], [], [], [], []]
for i in range(n):
    if a[i] != 0:
        if f:
            f = False
            if l == -1:
                if a[i] % 2 == 0:
                    z[0].append(i)
                else:
                    z[1].append(i)
            else:
                if a[i] % 2 == t:
                    if t == 0:
                        z[3].append(i - l - 1)
                    else:
                        z[4].append(i - l - 1)
                else:
                    z[2].append(i - l - 1)
        l = i
        t = a[i] % 2
    else:
        f = True
if a[-1] == 0:
    if l == -1:
        print(1)
        exit(0)
    else:
        if t == 0:
            z[0].append(n - l - 1)
        else:
            z[1].append(n - l - 1)
# print(z)
z[1].sort()
z[0].sort()
z[3].sort()
z[4].sort()
ans += len(z[2])
for i in range(len(z[3])):
    if z[3][i] <= e:
        e -= z[3][i]
    else:
        ans += ((len(z[3]) - i) * 2)
        break
for i in range(len(z[4])):
    if z[4][i] <= o:
        o -= z[4][i]
    else:
        ans += ((len(z[4]) - i) * 2)
        break
for i in range(len(z[0])):
    if z[0][i] <= e:
        e -= z[0][i]
    else:
        ans += (len(z[4]) - i)
        break
# print(o,e)
for i in range(len(z[1])):
    if z[1][i] <= o:
        o -= z[1][i]
    else:
        ans += (len(z[1]) - i)
        break
print(ans)
