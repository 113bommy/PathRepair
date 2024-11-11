balance = dict()
n = int(input())
s = input()
b = 0
ans = 0
balance[0] = -1
for i in range(n):
    if s[i] == "1":
        b += 1
    else:
        b -= 1
    if b in balance:
        ans = max(i - balance[b], ans)    
    else:
        balance[b] = i
    #print(ans, " ", balance)
    
print(ans)