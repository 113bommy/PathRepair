n,m = map(int, input().split())
iss = list(map(int, input().split()))
ii2 = []
for i in range(len(iss)):
    iss3 = iss[0:i+1]
    iss3.sort()
    iss3.reverse()
    k = 0
    ii = 0
    for j in range(i+1):
        k+= int(iss[j])
    if k <= m:
        ii2.append('0')
    else:
        while k > m:
            k -= int(iss3[0])
            iss3.pop(0)
            ii+=1
        ii2.append(str(ii))
print(' '.join(ii2))
