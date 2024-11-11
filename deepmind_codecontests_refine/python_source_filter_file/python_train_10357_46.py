n = int(input())
n1 = n%10
n2 = int(n/10)
if n == 10:
    print("ten")
elif n==11:
    print("eleven")
elif n==12:
    print("twelve")
elif n==40:
    print("forty")
else:
    num1 = {0: "zero",
            1: "one",
            2: "two",
            3: "three",
            4: "four",
            5: "five",
            6: "six",
            7: "seven",
            8: "eight",
            9: "nine"}
    num2 = {2: "twen",
            3: "thirt",
            4: "four",
            5: "fif",
            6: "six",
            7: "seven",
            8: "eigh",
            9: "nine"}
    if n<10:
        num_1 = num1[n] 
    elif n2 == 1:
        num_1 = num2[n1]+"teen"
    elif not n1:
        num_1 = num2[n2]+"ty"
    else:
        num_1 = num2[n2]+"ty-"+num1[n1]
    print(num_1)