t = int(input())
for _ in range(t):
    flag = 0
    s = input()
    if "0" in s and int(s)%3 == 0 and ("2" in s or "4" in s or "6" in s or "8" in s or int(s)==0 or s.count("0") > 2):
            print("red")
    else:
        print("cyan")