i=list(map(int,input().split()))
i.sort()
print('Yes' if i[0]+i[1]==i[2] else 'No')