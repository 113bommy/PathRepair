def fac(n):
    if n==1:
        return 1
    return n+fac(n-1)



t=int(input())
for i in range(t):
    n=input()
    print(10*(int(n[0])-1)+fac(len(n)))