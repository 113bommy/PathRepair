def catchOverflow(operations, N):
    mainStack = [1]
    summ = 0
    i = 0
    comparison = 2**32 - 1
	
    while i < N:
        if operations[i] == "add":
            summ += mainStack[-1]
        elif operations[i] == "end":
            mainStack.pop()
        else:
            temp = operations[i].split()
            iterations = int(temp[1])
            mainStack.append(min(iterations * mainStack[-1], comparison))
        i += 1
        
    if summ >= comparison:
        return "OVERFLOW!!!"
    else:
        return summ

N = int(input())
i = 0
operations = []
while i < N:
    operations.append(input())
    i += 1
print(catchOverflow(operations, N))