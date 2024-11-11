l = list(map(int,input().split()))
K = int(input())
print(sum(l)-max(l)+max(l)*2*K)