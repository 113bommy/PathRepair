n, x = (int(i) for i in input().split())
cur, result = 0, 0
for i in range(n):
    inp = [int(i) for i in input().split()]
    left = inp[0]-1
    right = inp[1]
    result += (right-left) + (left-cur) % x
    cur = right
print(result)