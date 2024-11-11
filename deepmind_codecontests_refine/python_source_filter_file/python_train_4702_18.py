inputLines = int(input())
constant = 1
stack = []    
init = 0
halt = False
     
for n in range(inputLines):
    
    l = input()
    
    if "for" in l:
        value = int(l.split()[1])
        if constant * value > (2**32)-1:
            stack.append(2**32-1)
        elif stack and stack[-1] == (2**32) - 1:
            if stack[-1] == (2**32) - 1:
                stack.append(2**32-1)
        else:
            constant *= value
            stack.append(value)
    elif "end" in l:
        value = stack[-1]
        if value != (2**32) - 1:
            constant /= stack[-1]
        stack.pop()
    elif "add" in l:
        if stack:
            if stack[-1] == (2**32)-1:
                init = True
        init += constant
     
if init > (2**32)-1 or halt:
    print("OVERFLOW!!!")
else:
    print(int(init))