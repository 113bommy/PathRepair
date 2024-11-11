num2words1 = {0: "", 1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', \
            6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten', \
            11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', \
            15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
num2words2 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

def number(Number):
    if Number == 0:
        return "0"
    elif 1 <= Number < 19:
        return num2words1[Number]
    elif 20 <= Number <= 99:
        tens, below_ten = divmod(Number, 10)
        return num2words2[tens - 2] + '-' + num2words1[below_ten]
    else:
        print("Number out of range")

a = number(int(input())).lower()
if a[-1] == '-':
    print(a[:-1])
else:
    print(a)
