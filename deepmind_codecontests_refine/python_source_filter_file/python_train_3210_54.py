a, b, k = map(int,input().split())
n = list(range(a,b+1))
print(*sorted(set(n[:k]) | set(n[-k:])),sep="\n")