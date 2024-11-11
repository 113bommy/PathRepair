
t = int(input())
 
for i in range(t):
    ans = 0
    if i > 0: line = input()
    n, x = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())), reverse=True)
    for j in range(n):
        if a[j]+b[j]>x:
            ans = 0
            break
 
    if ans == 1:
        print("Yes")
    else:
        print("No")