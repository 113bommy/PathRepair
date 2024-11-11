N=int(input())
print(sum(sorted(map(int, input().split()),reverse=True)[N:N*2]))