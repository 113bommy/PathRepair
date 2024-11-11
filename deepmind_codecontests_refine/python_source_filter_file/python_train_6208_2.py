arr = list(map(int,input().split()))
s1 = 0
s2 = 0
arr.sort()
s = sum(arr)
fl = False
for i in range(4):
    for g in range(i,5):
        for j in range(g,6):
            if arr[i] + arr[g] + arr[j] == s/2:
                fl = True
if fl:
    print("Yes")
else:
    print("No")