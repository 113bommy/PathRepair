t=int(input())
for _ in range(t):
    n=int(input())
    if n%9==0:
        print(n+int(n/10)+1)
    else:
        print(int(n/0.9))
    