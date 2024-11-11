num = int(input())

scores = list(map(int,input().split()))
scores = list(filter(lambda x:x!=0,scores))
scores = sorted(scores)
scores = tuple(scores)
print(len(scores))
