M = int(input())
dcnt = 0
calc = 0
for i in range(M) :
    c,d = map(int,input().split())
    dcnt += d
    calc += d*c

res = calc//9 + dcnt - 1
print(res)
