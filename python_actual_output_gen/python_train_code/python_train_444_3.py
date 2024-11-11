b, k =map(int,input().split())
A=list(map(int,input().split()))


an = A[-1] % 2


for i in range(k):
    if A[k - 1 - i] % 2 == 0:
        an += 2
    else:
        if b % 2 == 0:
            an += 2
        else:
            an += 1
        

if an & 1 == 0:print("even")
else:print("odd")