a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
def F(i,j,k):
    return not i and not j and not k
print(1 if d*b-a*e else 0 if F(a,b,c) or F(d,e,f) or c*e-b*f or a*f-c*d else -1)
