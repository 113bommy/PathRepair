for _ in range(int(input())):
    n=int(input())
    li=input()
    li1=li[n-1]

    for i in range(1,n):
        li1+=li[i]
    print(li1)