def getNumber():
    s = [int(i) for i in input().split()]
    a = (s[0]+s[1])//2
    b = (s[2]+s[3])//2
    if a==b:
        if a+1<=s[1]:
            a = a+1
        elif b+1<=s[3]:
            b=b+1
    print(a,b)
n = int(input())
print(n)
for i in range(0,n):
    getNumber()