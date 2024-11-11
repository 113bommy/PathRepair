N = int(input())
S = input()

w_left = 0
e_right = S[1:].count("E")
ans = float('inf')
for i in range(N-1):
    if i != 0:
        if S[i+1] == "E":
            e_right -= 1
        elif S[i-1] == "W":
            w_left += 1
    ans = min(ans, w_left + e_right)
print(ans)
