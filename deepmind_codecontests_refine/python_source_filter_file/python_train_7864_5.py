n = int (input())
l = [int (x) for x in input().split()]

ans = "-1"
if n > 1:
    if l[-1] > l[-2]:
        ans = "UP"
    else:
        ans = "DOWN"
        
    if not (l[-1] and l[-2]):
        ans = "UP"
        
if l[0] == 15:
    ans = "DOWN"

if l[0] == 0:
    ans = "UP"
        
print (ans)