numbers = list(map(int,input().split()))
arithmetic_prog = numbers[1] - numbers[0]
geometric_prog = numbers[1] / numbers[0]

if numbers[3]-numbers[2] == arithmetic_prog and numbers[2]-numbers[1] == arithmetic_prog  :
    print(numbers[-1]+arithmetic_prog)
elif numbers[3]/numbers[2] == geometric_prog and numbers[2]/numbers[1] == geometric_prog :
    if numbers[3]*geometric_prog - int(numbers[3]*geometric_prog) == 0:
        print(int(numbers[-1]*geometric_prog))
    else:
        print(42)
    
else:
    print(42)
    
