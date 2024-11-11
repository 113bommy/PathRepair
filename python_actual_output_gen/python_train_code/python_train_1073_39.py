n = int(input())
s = input()
res = "0"
v = set(['a','e','i','o','u'])
for i in s:
    if i in v:
        if not res[-1] in v:
            res+=i
    else:
        res+=i
print(res[1::])
