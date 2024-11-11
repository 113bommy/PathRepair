def oddEven(a):
    odd,even = 0,0
    for n in a:
        if n%2==0:
            even+=1
        else:
            odd+=1
    return even,odd
n,m = list(map(int,input().split(' ')))
a = list(map(int,input().split(' ')))
b = list(map(int,input().split(' ')))
ea,oa = oddEven(a)
eb,ob = oddEven(b)
print(min(ea,ob)+min(oa,eb))
