n,k = list(map(int,input().split()))
a = [int(x) for x in input().split()]
c = 0
print(sum([c + 1 if i < k else c + 2 for i in a]))