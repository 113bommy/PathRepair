def p(n,st):
    k = 0
    arr = [ord(i) for i in st]
    ars = arr.copy()
    arr.sort()
    for i in range(n):
        if arr[i] != ars[i]:
            k += 1
    return k
a = []
for i in range(int(input())):
    n = int(input())
    st = input()
    a.append(p(n,st))
for i in a:
    print(a)