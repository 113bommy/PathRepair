t = int(input())
for _ in range(t):
    n = int(input())
    if n==1:
        print(1)
    elif n%2==0:
        print(n/2)
    else:
        print(int(n/2)+1)