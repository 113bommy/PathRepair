def calculator(a):
    if a%3 == 0 or a%7 == 0:
        return "YES"
    while a>=3:
        a-=7
        if a%3==0:
            return "YES"
    return "NO"
for i in range(int(input())):
    print(calculator(int(input())))
    
