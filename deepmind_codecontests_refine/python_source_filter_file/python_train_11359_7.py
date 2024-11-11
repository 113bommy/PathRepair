n = int(input())
rek = list(map(int,input().split()))
mx, pay = map(int,input().split())
ans = 0
import math
for i in rek:
    if i > mx:
        ans += pay * (math.ceil((i-pay)/(mx+pay)))
print(ans)