n = int(input())
d = int(input())
e = int(input())

dollar = 1*d
euro = 5*e

# using_dollar = n%dollar
# using_euro = n%euro
# using_dollar_euro = using_dollar % euro
# using_euro_dollar = using_euro % dollar

# print(min(using_dollar, using_euro, using_dollar_euro, using_euro_dollar))

ans = 1e15
temp = 0
while (temp<=n):
    ans = min(ans, (n-temp)%d)
    temp += e
print(ans)