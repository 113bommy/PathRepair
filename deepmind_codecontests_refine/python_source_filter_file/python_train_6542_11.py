#Biscuits

N,P = list(map(int, input().split()))
A = list(map(int, input().split()))

#奇数の数
k = 0
for a in A:
    k += a%2
if ( k ==0 ):
    ans = (3-P)%2 * 2**(N-1)
else:
    ans = 2**(N-1)
print(ans)