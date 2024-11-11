def f():
    l=[int(k)%3 for k in input().split()]
    a=sum([k==1 for k in l])
    b=sum([k==2 for k in l])
    a,b=sorted((a,b))
    c=len(l)-a-b
    return (a+c+(b-a)//2)
for k in range(int(input())):
    input()
    print(f())
