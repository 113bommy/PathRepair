n = int(input())
ans = ""
for a in range(n//4):
    n2 = n - (a * 4)
    if n2 % 7 == 0:
        b = n2 // 7
        for qt in range(a):
            ans += '4'
        for st in range(b):
            ans += '7'
        break
        
if ans == "":
    print(-1)
else:
    print(ans)