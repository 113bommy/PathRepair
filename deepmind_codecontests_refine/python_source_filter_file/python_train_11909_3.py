n= int(input())
if n  %2 == 1:
    a= [i for i in range(n)]
    a = map(str, a)
    c= [(2*i)%n for i in range(n)]
    c= map(str, c)
    a = ("".join(a))
    print(a)
    print(a)
    print(" ".join(c))

else:
    print(-1)

