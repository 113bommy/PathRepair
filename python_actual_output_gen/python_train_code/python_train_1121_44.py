A, B, K = map(int, input().split())

for i in range(A,min(B+1,A+K)):
    print(i)
for i in range(max(A+K,B-K),B+1):
    print(i)