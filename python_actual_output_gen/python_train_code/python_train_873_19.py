N = int(input())
D, X = map(int, input().split())
print(sum([D // int(input())+1 for i in range(N)])+X)