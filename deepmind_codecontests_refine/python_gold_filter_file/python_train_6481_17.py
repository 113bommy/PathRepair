T = int(input())
for t in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        if a[i]>1:
            break
    if i%2==0:
        print("First")
    else:
        print("Second")
        