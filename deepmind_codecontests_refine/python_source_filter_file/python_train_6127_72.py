S,C = map(int,input().split())
ans = min(S,C//2)
C -= 2*ans
ans += C//3

print(ans)