n = int(input())
num = list(input())

half = n // 2



if num.count('7') + num.count('4') == len(num) :
    st = '+'.join(num[:half])
    st2 = '+'.join(num[half:])
    if eval(st) == eval(st2):
        print("YES")
    else:
        print("NO")
else:
    print("NO") 