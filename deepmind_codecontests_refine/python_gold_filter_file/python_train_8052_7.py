n = int(input())
top = int(input())

to_p = -1
for _ in range(n):
    tmp = list(map(int, input().split()))
    left = tmp[0]
    right = tmp[1]
    if top == left or top == right or top == 7-left or top == 7-right:
        to_p = 1
    else:
        top = 7 - top
    
print("YES") if to_p == -1 else print('NO')

