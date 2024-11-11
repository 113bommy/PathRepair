def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

n = get_number()
A = []
B = []
zero_count = 0
for i in range(n):
    a = get_number()
    A.append(a)
    if(a == 0) :
        zero_count += 1
        B.append(1)
    else:
        B.append(-1)

def max_subarray(B):
    i = 0
    j = 0
    s = 0
    maxSum = 0
    tempMax = 0


    for k in range(0, len(B)):
        tempMax += B[k]
        if(tempMax > maxSum):
            # print(B[k])
            maxSum = tempMax
            i = s
            j = k
        if(tempMax < 0):
            s =  k + 1
            tempMax = 0
    return(maxSum, i, j)

if (zero_count == 0) :
    print(sum(A))
else:
    _, i, j = max_subarray(B)
    for k in range(i, j+1):
        A[k] = 1-A[k]
    print(sum(A))


