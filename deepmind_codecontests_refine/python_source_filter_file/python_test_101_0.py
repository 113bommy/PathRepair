T = int(input())
while T>0:
    T -= 1
    n = int(input())
    array = [int(x) for x in input().split()]
    color_string = input()
    blue = []
    red = []
    ans = "YES"
    for i in range(len(array)):
        if color_string[i] == 'B':
            blue.append(array[i])
        else:
            red.append(array[i])
    blue = sorted(blue)
    red = sorted(red)
    # print(blue)
    # print(red)
    for i in range(len(blue)):
        if i >= blue[i]:
            ans = "NO"
    for i in range(len(red)):
        if len(red) - i >= n - red[i]:
            ans = "NO"

    
    print(ans)