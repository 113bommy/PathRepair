input()

op = map(int, input().split(' '))
ans = 0
nextOp = 0

for o in op:
    if o == 0:
        ans += 1
        nextOp = 0
    elif o == 3:
        nextOp = -nextOp % 3
    else:
        if o == nextOp:
            ans += 1
            nextOp = 0
        else:
            nextOp = o
print(ans)

