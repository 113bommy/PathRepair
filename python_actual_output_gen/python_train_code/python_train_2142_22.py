s = input()
x = s.split(" ")
f = x[0]
sec = x[1]
ans=f[0]
f = f.replace(ans,"")
last = sec[0]
for i in f:
    if i<=last:
        ans+=i
    else:
        break
print(ans+last)