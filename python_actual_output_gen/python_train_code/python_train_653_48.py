n = int(input())
A = list(sorted(list(map(int,input().split())))[::-1])
print(sum(A[::2])-sum(A[1:2]))
