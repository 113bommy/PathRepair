a=int(input())

if a in (0,1):
    print(-1)
elif a%2==0:
    print(a**2//4+1,a**2//4-1)
else:
    print((a**2-1)//2,(a**2+1)//2)
