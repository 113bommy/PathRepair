t=int(input())
for _ in range(t):
    l1=list(map(int,input().split()))
    l1.sort()
    if l1[0]+l1[1]>=l1[2]:
        print("Yes")
    else:
        print("No")