n, m, k = tuple(map(int,input().split()))
p = []
i = 0
while i<=m:
    p.append(int(input()))
    i += 1
fedor = p.pop()

def dec2binsum(num):
    su = 0
    while True:
        num, remainder = divmod(num,2)
        su += remainder
        if num == 0:
            return su

friend = 0
for player in p:
    a = player^fedor
    su = dec2binsum(a)
    if su>k:
        break
    friend +=1

print(friend)

