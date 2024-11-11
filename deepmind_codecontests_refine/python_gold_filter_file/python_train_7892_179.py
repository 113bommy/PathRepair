K=list(map(int,input().split()))
t=int(input())
print(sum(K)-max(K)+max(K)*(2**t))