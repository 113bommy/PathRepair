N,a,b,c,d = map(int,input().split())
n = N - 1
ans = "No"
for i in range(n+1):
    m1 = i*d - (n-i)*c
    m2 = -1*(n-i)*d + i*c
    if m1 <= m2:
        if a + m1 <= b and b <= a+ m2:
            ans = "Yes"
            #print(m1,m2)
            break
    else:
        if a + m2 <= b and b <= a + m1:
            ans = "Yes"
            #print(m1,m2)
            break
print(ans)