n=int(input())
s=str(input())
c=[]
for i in range(3,n):
    if 65<=ord(s[i-3])<=77:
        d=abs(65-ord(s[i-3]))
    else:
        d=1+90-ord(s[i-3])

    if 65<=ord(s[i-2])<=79:
        d=d+abs(67-ord(s[i-2]))
    else:
        d=3+d+90-ord(s[i-2])

    if 72<=ord(s[i-1])<=90:
        d=d+abs(84-ord(s[i-1]))
    else:
        d=d+6+ord(s[i-1])-65

    if 65<=ord(s[i])<=83:
        d=d+abs(71-ord(s[i]))
    else:
        d=d+7+90-ord(s[i])
    c.append(d)
print(min(c))
