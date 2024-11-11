a=int(input())
for i in range(a):
    n=int(input())%4
    if n>2:
        print(4-n)
    else:
        print(n)