ONES = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven',
        'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen',
        'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']

DOZENS = ['twenty', 'thirty', 'fourty', 'fifty',
          'sixty', 'seventy', 'eighty', 'ninety']

n = int(input())

if n > 19:
    dozens, ones = divmod(n, 10)
    print(DOZENS[dozens - 2] + ('-' + ONES[ones] if ones else ''))
else:
    print(ONES[n])