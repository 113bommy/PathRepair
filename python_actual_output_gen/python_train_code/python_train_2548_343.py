N = int(input())
n = list(map(int,input().split()))
n = sorted(n,reverse=True)
print(sum(n[N:2*N]))