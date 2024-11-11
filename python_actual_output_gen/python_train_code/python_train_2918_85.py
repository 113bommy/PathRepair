a, b = list(map(int, input().split()))
kj=max(a,b)-min(a,b)//2
print(str(min(a,b)) + ' ' + str(max(a,b)-min(a,b)//2))
