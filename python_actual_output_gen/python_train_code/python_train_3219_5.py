
K,A,B = map(int, input().split())

if B <= A + 2 or K < A+2:
    print(K)
else:
    print((B-A)* ((K+1-A) //2 -1)+ B + (K+1-A) % 2)
