x,a,b = map(int,input().split())

ans = "delicious" if a > b else "safe"
ans = "dangerous" if b-a > x else ans
print(ans)