n, s, k = open(0)
j = s[int(k)-1]
print("".join(["*",j][i==j] for i in s)[:-1])