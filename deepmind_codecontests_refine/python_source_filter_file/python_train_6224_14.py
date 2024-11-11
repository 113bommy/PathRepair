S = input()
T = [0]*2019
T[0]=1
t = 0
ans = 0
dig = 1
for i in range(n):
    t = (t + (int(S[-i-1]))*dig)%2019
    dig = (dig*10)%2019
    T[t] += 1
for j in T:
    ans +=int(j*(j-1)/2)
print(ans)