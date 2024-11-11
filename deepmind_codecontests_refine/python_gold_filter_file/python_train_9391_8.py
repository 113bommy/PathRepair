def temporarilyUnavailableSingle(a,b,c,r):
    minLimit = min(a,b)
    maxLimit = max(a,b)
    a = minLimit
    b = maxLimit
    diff = b - a

    first = c - r
    second = c + r

    temp1 = min(b, second)
    temp2 = max(a, first)
    possible = temp1 - temp2
    exclude = max(possible,0)
    result = diff - exclude
    # print(result)
    # print("count is ", count)

    return result
def temporarilyUnavailable(givenInput):
    input = givenInput.split("\n")
    input = input[1:]
    result = ""

    for i in range(len(input)):
        singleLine = input[i]    
        singleLine = singleLine.split()

        a = singleLine[0]
        b = singleLine[1]
        c = singleLine[2]
        r = singleLine[3]
        a = eval(a)
        b = eval(b)
        c = eval(c)
        r = eval(r)

        singleResult = temporarilyUnavailableSingle(a,b,c,r)

        if i < len(input) - 1 :
            result = result + str(singleResult) + "\n"
        else:
            result = result + str(singleResult)

    print(result)

if __name__ == "__main__":
    n = eval(input())
    givenInput = str(n) + "\n"
    
    for i in range(n):
        singleLine = input()
        if i == n - 1:
            givenInput += singleLine
            continue
        givenInput += singleLine + "\n"
    temporarilyUnavailable(givenInput)

# 8 2 10 100
# 2 3 2 3