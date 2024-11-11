n,m = map(int,input().split())
print(str(n-1) + " " + str(16769023))
for i in range(1,n-1):
    print(str(i) + " " + str(i+1)+  " " + str(1))
x = 16769023

print(str(n-1) + " " + str(n) + " " + str(x-(n-2)))
m = m - (n-1)
for i in range(1,n+1):
    if m!=0:
        ok = True 
    else:
        ok = False 
    for j in range(i+1,n+1):
        if i == j or i == j + 1 or j == i + 1:
            continue 
        if ok == True:
            print(str(i) + " " + str(j) + " " + str(10**8))
        m -= 1 
        if m <= 0:
            ok = False
        if ok == False:
            break 
    if ok == False:
        break 