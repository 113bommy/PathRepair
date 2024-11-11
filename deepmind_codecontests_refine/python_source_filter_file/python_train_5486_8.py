import sys
n = int(input())
a = []
for i in range(n):
    a.append(input())


def f(d):
    return(len(d))


a.sort(key = f)
for i in range(2, n):
    if not(a[i - 1] in a[i]):
        print("NO")
        sys.exit()
print("YES")
for i in a:
    print(i)
