alth = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
s = input()
ai = [729,243,243,81,243,81,81,27,243,81,81,27,81,27,27,9,243,81,81,27,81,27,27,9,81,27,27,9,27,9,9,3,243,81,81,27,81,27,27,9,81,27,27,9,27,9,9,3,81,27,27,9,27,9,9,3,27,9,9,3,9,3,3,1]
ans = 1
for i in s:
    ans *= ai[alth.find(i)]
    ans %= 1000000007
print(ans)
