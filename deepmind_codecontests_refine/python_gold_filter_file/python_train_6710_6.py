def turnBitIntoInteger(bit,begin,end):
    i=1
    sum=0
    while begin < end:
        sum+=int(bit[begin])*i
        i=i*2
        begin+=1
    return sum
num=int(input())
str=input()
inhand="1"
count=0

# decimal=turnBitIntoInteger(str,0,len(str))
# binary=(bin(decimal+1)[2:].zfill(num))
# binary=binary[:-1]
# print(binary)
for i in str:
    if i == "0":
        if i != inhand:
            inhand="0"
            count+=1
            i="1"
    else:
        if i == inhand:
            inhand="1"
            count+=1
            i="0"
        else:
            inhand="0"
            count+=0
print(count)