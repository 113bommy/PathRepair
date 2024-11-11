am = int(input())
arr = list(map(int,input().split()))
s = 0
prefS = [0]
for i in range(am-1):
    s+=arr[i]
    prefS.append(s)
m = min(prefS)
for i in range(am):
    prefS[i]+=(-1*m)+1
if max(prefS) > am or (len(list(set(prefS))) < am):

    print(-1)
else:
    print(*prefS)