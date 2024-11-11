input()
K=int(input())
ans = [min(x-0,K-x) for x in list(map(int,input().split()))]
print(sum(ans))