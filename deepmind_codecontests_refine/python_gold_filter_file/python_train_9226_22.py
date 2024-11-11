n=int(input())
for i in range (n):
    t=int(input())
    a=t%3
    while a and t>=7:
        t-=7
        a=t%3
    if a:
        print("NO")
    else:
        print("YES")
