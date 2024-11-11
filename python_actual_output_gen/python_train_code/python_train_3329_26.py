n = int(input())
k = str(input())
s = 0
f = 0
for i in range (0, n-1):
    if k[i]+k[i+1] == "SF":
        f += 1
    if k[i]+k[i+1] == "FS":
        f += 1
if s >= f:
    print("No")
elif f > s:
    print ("Yes")