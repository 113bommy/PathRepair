n = int(input())
A = list(map(int, input().split()))
B = [0]*N

for i in A:
    B[i-1] += 1

for i in B:
    print(i)
