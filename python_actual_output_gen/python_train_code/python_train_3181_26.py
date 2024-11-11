n,*a=[int(input()) for i in range(4)]
m=sorted(a)[0]
print(n//m+5 if n%m>0 else n//m+4)