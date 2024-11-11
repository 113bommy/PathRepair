n = int(input())
s = [['*']*2]*(n+1)
for i in range(1, n+1):
    s[i] = list(map(int, input().split()))

count = 1
s[0] = [0, 0]
#cache = -1
for i in range(1, n+1):
    if s[i-1][0] + s[i-1][1] != 0:      
        if min(s[i]) >= max(s[i-1]) and s[i-1][0] == s[i-1][1]:
            count += min(s[i]) - max(s[i-1]) 
            #cache = min(s[i])
        elif min(s[i]) >= max(s[i-1]):
            count += min(s[i]) - max(s[i-1]) + 1  

print(count)
        
        
