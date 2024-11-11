l=[]
for i in range(1,10000):
    l.append(str(i))


n = int(input())
s = "".join(l)
print(s[i+1])