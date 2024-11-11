A = [int(input()) for _ in range(6)]
m = min(A[1:])
print(4+(A[0]+m-1)//m)