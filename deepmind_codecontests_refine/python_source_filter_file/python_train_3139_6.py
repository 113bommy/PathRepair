import sys

end = sys.exit

n , k = map(int,input().split())
l = list(map(int,input().split()))

temp = n
minn = n
for i in range(k):
    if n <= 0:
        print(i+1)
        end()
    minn = min(minn,temp)
    temp += l[i]

one_round = sum(l)

if one_round >= 0:
    print(-1)
    end()

rounds = (minn - one_round - 1) // (-one_round)

n += rounds*one_round

for i in range(k):
    if n <= 0:
        print( rounds*k + i )
        end()
    n += l[i]
