a,b=input().split()
a=int(a)
b=int(b)
if a!=b:
    min_m = min(a, b)
    max_m = max(a, b)
    print(min_m,int((max_m-min_m)/2))
else:
    print(a,0)


