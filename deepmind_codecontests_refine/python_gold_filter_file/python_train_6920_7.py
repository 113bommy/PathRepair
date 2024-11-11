# import sys
# sys.stdin = open("#input.txt", "r")
a,b = list(map(int, input().split()))
a,b = max(a,b),min(a,b)

ans = min(b,a-b)
a-=ans*2; b-=ans
if a>0 and b>0: ans+=(a+b)//3
print(ans)