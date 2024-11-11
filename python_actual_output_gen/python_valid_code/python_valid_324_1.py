def simple(n):
    a=set()
    i=1
    while i**2<=n:
        if n%i==0:
            a.add(i)
            a.add(n//i)
        i=i+1
    if len (a)>2:
        return 'Составное'
    return 'Простое'

x=int(input())
for i in range(x//2):
    if simple(i)=='Составное' and simple(x-i)=='Составное':
        print(i, x-i)
        break
        
