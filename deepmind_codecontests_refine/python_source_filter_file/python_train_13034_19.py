for _ in range(int(input())):
    n = int(input())
#n,k=map(int, input().split())
    arr = list(map(int, input().split()))
    s=sum(arr)
    x=0
    for i in arr:
        x^=i

    print(2)
    print(s, s+x)
#print(523833000*696657832*80612189*258079255)
#print(p)

#l,r=map(int, input().split())




