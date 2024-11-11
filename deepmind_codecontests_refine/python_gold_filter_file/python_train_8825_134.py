a,b = map(int,input().split())
ans = -1
for x in range(b*10,(b+1)*10):
    if a <= x*0.08 < a+1:
        ans = x
        break
print(ans)
