num1 = int(input())
num2 = int(input())
per1 = int(input())
per2 = int(input())
card = int(input())

total = num1 + num2


if per1<=per2:
    min_per = per1
    max_per = per2
    min_num = num1
    max_num = num2
else:
    min_per = per2
    max_per = per1
    min_num = num2
    max_num = num1
    
total = num1 + num2

old = card
old_num = 0
old_per = min_per
while True:
    if old_num==min_num:
        old_per = max_per
    old-=old_per
    old_num+=1
    if old==0:
        break
    if old<0:
        old_num-=1
        break
    

result2 = old_num

a1 = card - ((per1-1)*num1 + (per2-1)*num2)
if a1<=0:
    result1 = 0
else:
    result1 = a1

if total <result1 :
    result1 = total

print(result1,result2)