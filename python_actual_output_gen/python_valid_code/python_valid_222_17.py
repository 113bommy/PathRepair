input()
s=[list(map(int,input().split()))for i in range(n)]
print(sum(sorted([x[1]+x[0] for x in s])[::-2])-sum([x[1]for x in s]))