n=int(input())
for i in range(n):
    a=input()
    l=list(a)
    for i in range(len(l)):
        if i%2==0:
            print(l[i],end=""),
    print(l[len(l)-1]),
