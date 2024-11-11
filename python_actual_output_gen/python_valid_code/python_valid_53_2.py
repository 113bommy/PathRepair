number=[]
for i in range(0,5):
    number.append(int(input()))
total=list(range(1,number[4]+1))
d=[]
for i in range(0,4):
    if number[0]>=number[i]:
        d+=total[number[i]-1::number[i]]
e=set(d)
print(len(e))