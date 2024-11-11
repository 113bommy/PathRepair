s=input()
n=len(s)
z=0
l=['H','Q','9','+']
for i in range(n):
    if s[i] in l:
        z+=1
if z>0:
    print("YES")
else:
    print("NO")