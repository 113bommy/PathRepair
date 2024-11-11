import re
num_of_rounds=int(input())
count_mishka=0
count_chris=0
for i in range(num_of_rounds):
    number=str(input())
    x=re.findall(r"\d",number)
    y=[int(a) for a in x]
    if y[0]>y[1]:
     count_mishka+=1
    elif y[0]<y[1]:
     count_chris+=1
    else:
        continue
if count_chris>count_mishka:
    print("Chris")
elif count_chris<count_mishka:
    print("Mishka")
else:
    print("Friendship is magic")
        
