from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
    l1,r1,l2,r2=list(map(int, stdin.readline().split()))
    # a=list(map(int, stdin.readline().split()))
    if l1!=r2:print(l1,r2)
    else:print(r1,l2)