def largest(a,b,c):
    if a>=b and a>=c:
        return a
    elif b>=a and b>=c:
        return b
    else:
        return c

t=int(input())
list=[]
for i in range(t):
    a,b,c,n=[int(x) for x in input().split()]
    l=largest(a, b, c)
    d=3*l-a-b-c
    if n>=d and (n-d)%3==0:
        list.append("YES")
    else:
        list.append("NO")
for x in list:
    print(x)