t = int(input())
for i in range(t):
    n = int(input())
    k = (n-1)/2
    ans = k*(k+1)*(2*k+1)*4
    ans /= 3
    print(int(ans))