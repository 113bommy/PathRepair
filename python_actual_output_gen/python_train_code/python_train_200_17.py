for test in range(int(input())):
    s = input()
    if min(s.count('1'), s.count('0')) % 2 == 0:
        print("NET")
    else:
        print("YES")