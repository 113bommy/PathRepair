#code
n = input()

p=n.index('^')
print(p)
l=0
r=0
for i in range(len(n)):
    if n[i]!='=' and i!=p:
        k = n[i]
        if i<p:
            l+=(p-i)*int(k)
        elif i>p:
            r+=(i-p)*int(k)
if l==r:
    print("balance")
elif l>r:
    print("left")
else:
    print("right")
    