N = int(input())
S = input()
 
left = 0
right = S[0:].count("E")
ans = left + right

for i in range(1, N):
    if S[i - 1] == "W":
        left += 1
    if S[i] == "E":
        right -= 1 
    ans = min(ans, left + right)
print(ans)