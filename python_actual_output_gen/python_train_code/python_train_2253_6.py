a = []
b = 0

while True:
    try:
        s=input()
        a += [s]
        b = max(b, len(s))
    except: break

b += 2
print("*"*b)
count=1
for each in a:
    t = b - 2 - len(each)
    if t % 2 == 0:
        print("*"+" "*(t//2) + each + " "*(t//2)+"*")
    else:
        y=t//2
        if count%2:
            print("*"+" "*(y+1)+each+" "*(y)+"*")
        else:
            print("*"+" "*(y)+each+" "*(y+1)+"*")
        count+=1
print("*"*b)