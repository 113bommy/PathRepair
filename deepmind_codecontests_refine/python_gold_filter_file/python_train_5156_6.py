s = input()
n = int(s[0] + s[2] + s[4] + s[3] + s[1])
res = n ** 5 % (10 ** 5)

st = ""
n = res
if n < 10:
    st += "0"
if n < 100:
    st += "0"
if n < 1000:
    st += "0"
if n < 10000:
    st += "0"
print(st, res, sep="")
