def factorial(a):
    if a==0:
        return 1
    else:
        return a*factorial(a-1)
n=int(input())
ans=2*factorial(n-1)/n
print(int(ans))