n,m,d = map(int, input().split())
T = list(map(int, input().split()))
R = [0 for _ in range(n+2)]
p = 0
cont = 1
while cont<m+1:
    p+=d
    ret = 0
    for i in range(p, p+T[cont-1]):
        if i-ret > n+1: ret += i-n-1
        if i-ret > n:
            # print('paso')
            R.remove(0)
            ret+=1
            R.append(0)
        # print(i)
        R[i-ret] = cont
        # print(R)
    p+=T[cont-1]-1
    p -= ret
    cont+=1
p+=d
# print(R)
if p < n+1:
    print('No')
else:
    print('Yes')
    for i in range(1,n+1):
        print(R[i], end=' ')
    print()

