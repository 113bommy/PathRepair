A = sorted(list(map(int,input().split())))
N = int(input())
A[-1] = A[-1]**N
print(sum(A))