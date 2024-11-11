n = int(input())
m = map(int,input().split())
mina = 0
minb = 0
for i in m:
    if i <=500000:
        mina = max(mina,i-1)
    else:
        minb = max(minb,1000000-i)
print(max(mina,minb))
