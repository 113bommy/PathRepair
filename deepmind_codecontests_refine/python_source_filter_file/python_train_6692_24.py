y=0
for i in range(int(input())):
    Str = input()
    x = list(map(int,Str))
    y = 10*(x[0]-1)+(len(x)*(len(x)+1))/2
    print(y)
