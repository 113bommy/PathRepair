# cook your dish here
T = int(input())
for _ in range(T):
    N = int(input())
    if N == 0 or N == 1 or N == 2:
        print(0)
    else:
        if N%2==0:
            print((N/2)-1)
        else:
            print(N//2)