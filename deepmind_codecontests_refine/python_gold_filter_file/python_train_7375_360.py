N = int(input())
a = list(map(int,input().split()))
print(sum(sorted(a)[N::2]))