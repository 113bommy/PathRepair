def square(a,b):
    if a==b:
        return 4*(a**2)
    return max(min(a,b)**2,max(a,b))
for _ in range(int(input())):
    a,b=map(int,input().split())
    print(square(a,b))
