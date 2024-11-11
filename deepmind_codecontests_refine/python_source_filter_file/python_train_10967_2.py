n , k = map(int , input().split())
l = list(map (int , input().split()))
i = 1
while k:
    if l[i-1] < l[i]-1 and l[i+1] < l[i]-1 :
        l[i]-=1
    k-=1
    i+=2
print(*l)