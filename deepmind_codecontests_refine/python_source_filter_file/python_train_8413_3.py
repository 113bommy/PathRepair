t= int(input())
for i in range(t):
    k=input().split()
    a=int(k[0])
    b=int(k[1])
    c=a*b
    d=int(c**.5)
    print(2*d-1-((d*(d+1)>=c)-(c==d*d and a!=b))