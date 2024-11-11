number=input()

num1=0
num2=0
num3=0
for i in range(len(number)):
      if number[i] == '0':
          num1=num1+1

      elif number[i] == '1':
          num2 = num2 + 1
      else:
          num3=num3+1

if num3 !=0 or num1==0 or num2==0:
    exit()

count=1
if len(number)<=100 and len(number)>=2:
    for j in range(len(number)-1):
        if number[j]==number[j+1]:
            count=count+1
            if count >= 7:
                print("Yes")
                exit()
        else:
            count=1

    print("No")



