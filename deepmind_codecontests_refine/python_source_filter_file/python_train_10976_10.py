n,k = map(int,input().split())

l = [int(x) for x in input().split() if int(x) < 5-k]

print(len(l) // 3)
