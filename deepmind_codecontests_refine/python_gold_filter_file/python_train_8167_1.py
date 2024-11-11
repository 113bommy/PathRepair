def test():
    n ,t=map(int,input().split(" "))
    a = list(map(int,input().split(" ")))

    p=0

    while p<t-1:
        p+=a[p]

    if p==t-1:
        return "YES"
    else:
        return "NO"

print(test())