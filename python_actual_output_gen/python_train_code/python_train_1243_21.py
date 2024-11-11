x , y = map(int, input().split(" "))
carry = y
distress = 0
for i in range(x):
    c , d = input().split(" ")
    d = int(d)
    if c == '+':
        carry+=d
    elif c == '-':
        if(carry-d >= 0):
            carry-=d
        else:
            distress += 1
    

print("{} , {}".format(carry, distress))
