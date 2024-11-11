for _ in range(int(input())):
    n=int(input())
    x=set()
    for i in range(1,int(n**0.5)+1):
        x.add(n//i)
        x.add(i)
    x.add(0)
    print(len(x))
    print(" ".join(map(str,x)))