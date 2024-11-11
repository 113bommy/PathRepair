n, m = map(int, input().split())
s = 0
for i in range(0, (n+1)//2):
    if(m >= i):
        t = min((n-(2*i)), ((m-i)//2))
        s = max(s, t+i)
print(s)
