n=int(input())
for _ in range(n):
    a=int(input())
    b=int(input())
    ab=a+b
    print(ab if ab<=10**80 else "overflow")