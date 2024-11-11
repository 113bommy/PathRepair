n=int(input())
p=2
for i in range(2,n+2):
    q=i*(i-1)
    r=q*q
    print(int((r-p)/(i-1)))
    p=q