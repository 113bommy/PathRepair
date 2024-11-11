N = int( input() )


ans = ''
while N:
    ans = str(abs(N % (-2))) + ans
    N = - (N//2)
    # print(N,ans)

print(ans)