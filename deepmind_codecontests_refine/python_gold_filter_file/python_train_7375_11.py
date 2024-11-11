N=int(input())
print(sum(sorted(map(int,input().split()))[N::2]))
