H, W, A, B = map(int, input().split())

arow = '1'*A + '0'*(W-A)
brow = '0'*A + '1'*(W-A)

for i in range(1,H):
    if (i <= B):
        print(brow)
    else:
        print(arow)