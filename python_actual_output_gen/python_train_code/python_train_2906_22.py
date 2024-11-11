t=int(input())
for _ in range(t):
    n=int(input())
    l1=[int(i) for i in input().split()]
    l2=[]
    for i in range(len(l1)):
        if l1[i] not in l2:
            l2.append(l1[i])
    for i in range(n):
        print(l2[i],end=" ")
    print(l2[n-1])