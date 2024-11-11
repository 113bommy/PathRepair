def p(n):
    if n==2:return 1
    if not n&1:return 0
    return pow(2,n-1,n)
print(sum(1 for _ in range(int(input())) if p(int(input()))))