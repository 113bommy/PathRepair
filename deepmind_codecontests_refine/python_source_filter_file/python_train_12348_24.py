n = int(input())//2
A = sorted(map(int, input().split()))

print(('NO','YES')[A[n-1]<A[n]])