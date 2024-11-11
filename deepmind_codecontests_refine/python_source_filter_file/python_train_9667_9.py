H,W = map(int, input().split())
fields = [list(input()) for i in range(H)]

for f in fields:
    cnt += f.count("#")
if cnt == H + W - 1: 
    print("Possible")
else:
    print("Impossible")