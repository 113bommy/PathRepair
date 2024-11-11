def answer(n):
    m=10**9+7
    return pow(3,3*n,m)-pow(7,n,m)

n=int(input())
print(answer(n))