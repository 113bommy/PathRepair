n=int(input())
for i in range(n):
    a=int(input())
    b=int(input())
    if a+b>=10**79:print("overflow")
    else:print(a+b)
