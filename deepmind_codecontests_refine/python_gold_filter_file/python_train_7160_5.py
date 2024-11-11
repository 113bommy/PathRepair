S = input()
N = len(S)

ans = 'No'
if S == S[::-1]:
    if S[:N//2] == S[(N//2)-1::-1]:
        ans = 'Yes'

print(ans)