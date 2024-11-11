def small_3(num1,num2,num3):
    if num1< num2 and num1<num3:
        return num1
    elif num2<num1 and num2<num3:
        return num2
    else:
        return num3

def small_2(num1,num2):
     if num1<num2:
         return num1
     else:
         return num2

a,b,c,d=[int(i) for i in input().split()]
sum=0
least=small_3(a,c,d)

for i in range(0,least,1):
    sum+=256

remaining=a-least

thirty_two=small_2(remaining,b)

for i in range(0,thirty_two,1):
    sum+=32

print(sum)
