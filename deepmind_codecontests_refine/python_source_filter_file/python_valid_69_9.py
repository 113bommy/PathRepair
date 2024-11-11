def check(s,po):
    l1 = list(str(s))
    l2 = list(str(po))
    i = 0
    j = 0
    d = 0

    while i<len(l1) and j<len(l2):
        if l1[i]==l2[j]:
            i = i +1
            j =  j +1
        else:
            d = d+1
            i = i +1

    add = len(l2) - j
    d = d + len(l1) - i
    return add+ d

def solve():
    s = int(input())
    ans = 1000000000
    for i in p:
        ans = min(ans, check(s,i))
    print(ans)


p = []
for i in range(37):
    p.append(2**i)
# print(p)


for testis  in range(int(input())):
    solve()
