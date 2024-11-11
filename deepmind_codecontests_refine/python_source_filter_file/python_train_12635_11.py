n , k = map(int,input().split())
l = list(map(int,input().split()))


for i in range(n):
    if ( k > 0 and l[i] < 0  ) :
        l[i] = -1 * l[i]
        k -=1


l = sorted(l)
print(l)

if k % 2 == 1 :
    l[0] = l[0] * - 1

print(sum(l))
