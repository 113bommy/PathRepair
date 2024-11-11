n = int(input())
for i in range(n):
    l1,r1,l2,r2 = map(int,input().split())
    if l1 != r2:
        print(l1,r2)
    elif r1!= l2:
        print(l2,r1)