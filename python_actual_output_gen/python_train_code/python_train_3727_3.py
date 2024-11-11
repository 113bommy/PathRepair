def notp(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return 1
    return 0
k = int(input())
a,f = "Ashishgup","FastestFinger"
for i in range(k):
    n = int(input())
    if n ==2:
        print(a)
    elif (n==1):
        print(f)
    elif n%2==0 and notp(n//2)==0:
        print(f)
    else:
        print(a)
    