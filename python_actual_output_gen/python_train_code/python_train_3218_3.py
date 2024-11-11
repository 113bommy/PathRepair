N = list(map(int,input().split()))
M = 10**9 + 7
red = N[0] - N[1]
x = red+1
print(x)
for i in range(2,N[1]+1):
    x *= (red+2-i)*(N[1]-i+1)//(i*(i-1))
    print(int(x%M))