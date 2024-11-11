def create_number():
    s = ""
    for i in range(n):
        if i == 0:
            s = s + "7"
            continue
        if (i - 1)%6 == 0 and i != 1:
            s = s + "7"
            continue
        s = s + "2"
    return s

numcases = input()
numcases = int(numcases)

for i in range(numcases):
    n = int(input())
    if n == 1:
        print("-1")
    else:
        string = create_number()
        print(string[::-1])