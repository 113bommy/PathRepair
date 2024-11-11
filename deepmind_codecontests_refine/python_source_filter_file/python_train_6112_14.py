n = [int(i) for i in input().split()]
l = [int(i) for i in input().split()]
l1 = [int(i) for i in input().split()]
ans=""
for i in l:
    if i in l1:
        ans += str(i)
        
print(ans)