from collections import defaultdict

MyDict = defaultdict(int)
X = list(map(int, input().split()))
for i in range(X[1]):
    Temp = list(map(int, input().split()))
    MyDict[Temp.index(max(Temp))] += 1
Max = max(MyDict.values())
for key in sorted(MyDict.keys()):
    if MyDict[key] == Max:
        print(key + 1)
        exit()
