n,k=tuple(map(int,input().split()))
li=[int(i) for i in input().split()]

kli=[i for i in range(1,k+1)]
sli=sorted(li)

wli=[1 for i in range(sli[0])]
kli=kli+wli

for i in li:
    if i>=len(kli):
        print('NO')
        break
else:
    print('YES')
    for i in li:
        print(' '.join(map(str,kli[0:i])))
