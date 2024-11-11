n = input()
ans = 26
q = 25
for i in range(len(n)):
    ans += q
    q-=1
print(ans)