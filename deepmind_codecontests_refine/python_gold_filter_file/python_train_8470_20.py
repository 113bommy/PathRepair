n=int(input())
for i in range(n+1, 10000):
    s=str(i)
    a=set()
    j=i
    while i>0:
        r=i%10
        a.add(r)
        i=i//10
    
    if len(a)==4:
        print(j)
        break  