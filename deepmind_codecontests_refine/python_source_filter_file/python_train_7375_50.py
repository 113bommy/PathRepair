N = int(input())
print(sum(sorted(
  list(map(int,input().split())) )[N:2*N]))