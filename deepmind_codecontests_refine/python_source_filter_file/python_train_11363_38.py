n=int(input())
if n==3:
    print(6)
elif n==4:
    print(18)
else:
    a=18
    for i in range(n-4):
        a+=i*(i-1)
    print(a)