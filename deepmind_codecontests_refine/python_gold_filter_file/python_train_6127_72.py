S,C = map(int,input().split())
ans = min(S,C//2)
C -= ans*2
ans += C//4
print(ans)