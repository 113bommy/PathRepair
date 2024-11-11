def dec(text,d):
    r=[]
    for i in text:
        c=ord(i)
        if c<65:r.append(i)
        elif c<91:r.append(chr((c-65+d)%26+65))
        else:r.append(chr((c-97+d)%26+97))
    return "".join(r)

while True:
    try:raw=input()
    except:break
    if raw=="":break
    for i in range(25):
        d=dec(raw,i+1)
        if sum([1 for i in ["the","this","that"] if i in d])>0:break
    print(d)
