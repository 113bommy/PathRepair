b = list (input().split())

need = [1, 1, 2, 7, 9]
ans = 100000
for i in range (5):
    ans = min (ans, int(b[i]) // need[i])
    
print (ans)
