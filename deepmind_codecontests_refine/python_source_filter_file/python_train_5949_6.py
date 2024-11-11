inp = [int(x) for x in input().split()]
n,m = inp[:2]
k = inp[-1]

l = [int(x) for x in input().split()]
arr = [[i,j] for i,j in enumerate(l)]

arr = sorted(arr , key=lambda x : x[1] , reverse=True)

summ = 0
for i in range(m*k) :
    summ+=arr[i][1]

print(summ)

rs = [i[0]+1 for  i in arr[:m*k+1]]
rs.sort()

frs = []

for i in range(m-1,m*(k-1),m):
    frs.append(str(rs[i]))

print(' '.join(frs))
