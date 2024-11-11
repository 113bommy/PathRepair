# coding=utf-8


if __name__ == '__main__':
    s = int(input())
    list_0 = ['zero', '	one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    list_00 = ['ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen',
               'nineteen']
    list_000 = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
    if s < 10:
        print(list_0[s])
    elif s < 20:
        print(list_00[s - 10])
    elif s % 10 == 0:
        print(list_000[(s - 20) // 10])
    else:
        print(list_000[(s - 20) // 10] + '-' + list_0[s % 10])
