from copy import deepcopy
n,k,m = map(int, input().split())
arr = list(map(int, input().split()))
arr2 = sorted(arr, reverse=True)
print(sum(arr2[:m * k]))
arr = sorted([(y,x) for x,y in enumerate(arr)], reverse=True)
ids = sorted([y for x,y in arr[:m * k]])
print(" ".join([str(x+1) for x in ids[k-1::k]][:-1]))
#print(" ".join([x+1 for x in ids[k-1::k]]))