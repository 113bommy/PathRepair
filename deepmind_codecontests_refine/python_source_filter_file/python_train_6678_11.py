import collections
n = int(input())
a = input().split(" ")
count = collections.Counter()
at = []
for el in a:
    count[el] += 1
    at.append(int(el))
a = at
k = max(count, key=count.get)
tk = int(k)
print(n - count[k])
pos = 0
con = 0
tcon = 0
arcon = 0
while pos < n:
    if a[pos] == tk:
        arcon += 1
        while con > tcon:
            if a[con-1] > a[con]:
                print(2,con-1 + 1, con+ 1)
            else:
                print(1,con-1 + 1, con + 1)
            con -= 1
            a[con-1] = a[con]
        tcon = pos + 1
        con = pos
        if arcon == count[k]:
            while pos < n -1:
                if a[pos + 1] > a[pos]:
                    print(2,pos + 2, pos + 1)
                else:
                    print(1,pos + 2, pos + 1)
                a[pos + 1] = a[pos]
                pos += 1
    con += 1
    pos += 1
