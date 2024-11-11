def check(s,po):
    l1 = list(str(s))
    l2 = list(str(po))
    i = 0
    j = 0
    d = 0

    while i<len(l1) and j<len(l2):
        if l1[i]==l2[j]:
            j =  j +1              # bcz append at right
        
        i = i +1

    d = d + len(l1) - j     #remove them
    d = d + len(l2) - j      #add rest
    return d

def solve():
    s = int(input())
    ans = 1000000000
    for i in p:
        ans = min(ans, check(s,i))
    print(ans)


p = []
for i in range(64):
    p.append(2**i)
# print(p)


for testis  in range(int(input())):
    solve()
