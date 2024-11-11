b=[]
t=0
for i in range(6):
    b.append(int(input()))
if b[4] > b[5] :
    if b[0]>b[3] or b[0]==b[3]:t= b[4]*b[3]
    else:
        t=t+b[4]*b[0]
        b[3] -=b[0]
        c=[b[1],b[2],b[3]]
        c.sort()
        t=t+b[5]*c[0]
else:
    c = [b[1], b[2], b[3]]
    c.sort()
    t = t + b[5] * c[0]
    b[3] -=c[0]
    if b[0] > b[3] or b[0] == b[3]: t =t+ b[4] * b[3]
    else:t = t + b[4] * c[0]
print(t)
