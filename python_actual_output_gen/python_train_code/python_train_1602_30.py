n = int(input())
l = [5,0,2,4,1,3]
l.reverse()
res = 0
for i in l:
    res += (n%2) * (2 ** l[i])
    n //= 2
print(res)