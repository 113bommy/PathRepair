count = 0
days = input()
log = input()
incount = 0
outcount = 0
for i in range(len(log)-1):
    matcher = log[i:i+2]
    if matcher == "SF":
        incount +=1
    elif matcher == "FS":
        outcount +=1

if outcount >= incount:
    print("NO")
else:
    print("YES")
