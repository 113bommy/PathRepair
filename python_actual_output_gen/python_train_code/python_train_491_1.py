def chk(x,y,x1,y1,x2,y2):
    if x==x1 or y==y1:
        return False
    if x==x2 and y==y2:
        return False
    if abs(x-x1)*abs(y-y1)==2:
        return False
    if abs(x-x2)*abs(y-y2)==2:
        return False
    return True

s=input()
x1=ord(s[0])-ord('a')
y1=int(s[1])-1
s=input()
x2=ord(s[0])-ord('a')
y2=int(s[1])-1
ans=0
for i in range(8):
    for j in range(8):
        if chk(i,j,x1,y1,x2,y1):
            ans+=1
print(ans)
