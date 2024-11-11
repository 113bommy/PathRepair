n, = map(int, input().split())
num1={0:"zero",1:'one',2:'two',3:'three',4:'four',5:'five',6:'six',7:'seven',\
      8:'eight',9:'nine',10:'ten',11:'eleven',12:'twelve',13:'thirten',\
      14:'fourteen',15:'fifteen',16:'sixteen',17:'seventeen',18:'eighteen',\
      19:'nineteen',}
num2 = (' ', ' ', 'twenty', 'thirty', 'fourty', 'fifty', 'sixty', 'seventy',
        'eighty', 'ninety')

if n < 20:
    print(num1[n])
elif n % 10 == 0:
    print(num2[n // 10])
else:
    print(num2[n // 10] + "-" + num1[n % 10])
