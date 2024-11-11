def find(n, k):
    ans = 0
    p = 1
    while p < n:
        p *= k
        ans += 1
    return ans
        
l, r = map(int, input().split())    

answer = 0
for x in range(find(r, 2)):
    for y in range(find(r, 3)):
        a = 2**x * 3 ** y
        if l <= a <= r:
            answer += 1
print(answer)