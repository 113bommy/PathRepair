A = int(input())
B = int(input())
N = A + B + 1
i = 0
c = [0] * N
while i < A:
    c[i] = str(i+1)
    i+=1
c[i] = str(N)
i += 1
while i < N:
    c[i] = str(N - i + A)
    i+=1
print(" ".join(c))
    
