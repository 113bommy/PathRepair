numlist = list(input().split())
print(sorted(numlist,key=lambda x:numlist.sount(x))[0])