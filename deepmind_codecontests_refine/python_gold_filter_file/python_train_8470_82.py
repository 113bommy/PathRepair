y=input()
for i in range(int(y)+1,9999):
    n=list(str(i))
    a,b,c,d=n
    if a!=b and a!=c and a!=d and b!=c and b!=d and c!=d:
        print(i)
        break
    