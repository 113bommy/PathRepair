n, a = map(int, input().split())
a-=1;
t = list(map(int, input().split()))
t1 = t[:a]
t2 = t[a+1:n]
ans = t[a]
for i in range(1, min(len(t2), len(t1))+1):
    ans += (t[a-i] == t[a+i] == 1)*2
if len(t2) > len(t1):
    for i in range(len(t1)*2 + 1, len(t2)):
        ans += t2[i]  
elif len(t1) > len(t2):
    for i in range(len(t1) - len(t2)):
        ans += t1[i]  
print(ans)