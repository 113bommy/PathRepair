n, k1, k2 = input().split()
a1 = input().split()
a2 = input().split()
res = []
for i in range(len(a1)):
    res.append(int(a1[i])-int(a2[i]))
res = [abs(i) for i in res]
k = int(k1) + int(k2)
k = int(k)
n = int(n)
if sum(res) < int(k):
    # big = (k-sum(res))//n
    # small = (k-sum(res))%n
    # res = small*((big+1)**2)+(n-small)*(big**2)
    if (k - sum(res)) // 2:
        print('0')
    else:
        print('1')
elif sum(res)==k:
    print('0')
else:
    while(k):
        res.sort()
        res[-1] = res[-1]-1
        k -= 1
    result = 0
    for i in res:
        result += i**2
    print(result)
