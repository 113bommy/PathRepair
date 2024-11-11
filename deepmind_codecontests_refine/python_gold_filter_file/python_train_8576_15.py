entrada=int(input())
if entrada> 0:
    print(entrada)
else:
    string = str(entrada)
    if string[-1]> string[-2]:
        string = string[:-1]
    else:
        string  = string[:-2]+string[-1]

    print(int(string))