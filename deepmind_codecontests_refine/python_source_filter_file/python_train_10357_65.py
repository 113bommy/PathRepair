__author__ = 'hamed1soleimani'

_0_9_1 = ['zero', 'one', 'tow', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
_11_19_1 = ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
_10_90_10 = ['ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

i = int(input())

if i < 10:
    print(_0_9_1[i])
elif i % 10 == 0:
    print(_10_90_10[i // 10 - 1])
elif i < 20:
    print(_11_19_1[i - 11])
else:
    print(_10_90_10[i // 10 - 1] + '-' + _0_9_1[i % 10])



