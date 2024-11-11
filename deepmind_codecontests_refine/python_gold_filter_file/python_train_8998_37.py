s = input()
ans = 1
temp = len(s)
if(temp>=2):
    temp2 = int(s[temp-2:temp])
    if temp2%4 == 0:
        ans += 7
    else:
        ans += 2**(temp2%4)
        ans += 3**(temp2%4)
else:
    ans += (2**int(s) + 3**int(s))
if int(s[temp-1])%2==0:
    ans += 6
else:
    ans += 4
print(ans%5)
