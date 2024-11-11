n = int(input())
ans , h = 2*n -1 , 0
for i in range(n):
    j = int(input())
    ans += abs(h-j)
    h = j
#print(ans)
print(ans)