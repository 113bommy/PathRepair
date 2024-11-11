n = int(input())
A = list(map(int, input().split()))
 
 
 
 
l = 0
r = n-1
alice = 0
bob = 0
p = 0

if n == 1:
    print(1,0)
elif n == 2:
    print(A[0], A[1])
else:
    for i in range(n):
        if (A[r] == A[l]):
            alice += 1
            bob += 1
            l += 1
            r -= 1
            p = 2
        elif A[l] == max(A[l], A[r]):
            bob += 1
            A[l] = A[l] - A[r]
            A[r] = 0
            r -= 1
            p = 2
        elif A[r] == max(A[l], A[r]):
            alice += 1
            A[r] = A[r] - A[l]
            A[l] = 0
            l += 1  
            p = 1
        if l == r:
            if p == 1:
                bob += 1
            if p == 2 or p == 0:
                alice += 1
            break
        if l > r:
            break
    print(alice, bob)