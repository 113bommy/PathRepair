q= int(input())
w=True
e=[q]

while w:
    q=q+1
    r=True
    while r:
        if q%10==0:
            q=q//10
        else:
            r=False
    e.append(q)
    if len(e)!=len(list(set(e))):
        break
print((len(e)-1),e)
