n, m = map(int,input().split())
if m == 0: print("YES"); exit(0)
arr = [int(i) for i in input().split()]
arr.sort()
i=0
if n in arr or m==1: print("NO"); exit(0)
while(i<len(arr)-2):
    if arr[i+2]-arr[i] == 2: print("NO"); exit(0)
    i+=1
print("YES")