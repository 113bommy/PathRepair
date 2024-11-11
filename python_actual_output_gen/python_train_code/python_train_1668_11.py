t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    x=0
    while s.count("()")>0:
        s=s.replace('()',"")
    n=n//2
    x=len(s)//2
    print(n-x)