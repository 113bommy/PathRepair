x,k,d = ,ap(int,input().split())
x = abs(x)
if x-k*d>0:
    print(x-k*d)
elif (k-x//d)%2 ==1:
    print(abs(x%d-d))
else:
    print(x%d)