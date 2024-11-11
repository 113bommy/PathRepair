N = int(input())
print(sum(sorted(map(int, input().split()))[N:3*N:2]))