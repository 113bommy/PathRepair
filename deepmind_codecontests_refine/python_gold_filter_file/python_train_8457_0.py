t=int(input())
for _ in range(t):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    if len(set(l2))==1 and sorted(l1)!=l1:
        print("No")
    else:
        print("Yes")