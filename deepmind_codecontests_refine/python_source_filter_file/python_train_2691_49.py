from math import ceil

N, A, B = map(int, input().split())
H = []
for _ in range(N):
    H.append(int(input()))
    
left = 0
right = max(H)//B + 1

while right - left > 2:
    mid = (right + left) // 2
    c = sum([ceil((h-B*mid)/(A-B)) for h in H if h > B*mid])
    
    if c > mid:
        left = mid
    else:
        right = mid
print(right)