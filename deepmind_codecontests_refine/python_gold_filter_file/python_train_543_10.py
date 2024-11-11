for _ in range(int(input())):
    n=int(input())
    r=0
    for i in range(1,n//2+1):
        r=r+(2*i+1)*i
        r=r+(2*i+1)*i
        r=r+(2*i+1-2)*i
        r=r+(2*i+1-2)*i
    print(r)
        