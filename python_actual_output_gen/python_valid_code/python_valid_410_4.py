n = int(input())
strEnd1 = "I love it"
strEnd2 = "I hate it"
result = ""
if n == 1:
    print(strEnd2)
elif n == 2:
    print("I hate that I love it")
else:
    for i in range(0, n - 1):
        if i % 2 == 0:
           result = result + "I love that "
        else:
            result = result + "I hate that "
    if n % 2 == 0:
        result = result + strEnd1
    else:
        result = result + strEnd2
    print(result)
