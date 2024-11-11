t=int(input())
for i in range(t):
    n=int(input())
    s=[int(j) for j in input().split()]
    a=s.count(0)
    b=sum(s)+a
    if b<=0:
        a=a+(-b)+1
    print(a)
