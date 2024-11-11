t=int(input())
for _ in range(t):
    n=int(input())
    if n<=2:
        print(1)
    else:
        print(n-1//2)