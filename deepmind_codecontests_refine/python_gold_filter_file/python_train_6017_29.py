n,m,v,p = map(int,input().split())
a = list(map(int,input().split()))
a.sort(reverse = True)
ans = p
border = a[p-1]
to_border = 0
for i in range(p,n):
    new_border = a[i] + m
    if new_border < border:
        print(ans)
        exit()
    possible_votes = 0
    possible_votes += (n+p-i-1)*m
    possible_votes += to_border
    possible_votes += (new_border-border)*(i-p+1)
    if possible_votes >= m*v:
        ans += 1
        to_border += border-a[i]
    else:
        print(ans)
        exit()
print(ans)
exit()
