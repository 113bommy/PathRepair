N = int(input())
n = list(map(int,input().split()))
n = sorted(n,reverse=True)
print(sum(n[1:2*N:2]))