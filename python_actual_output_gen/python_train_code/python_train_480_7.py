n = int(input())
for i in range(n):
    s = list(input())
    if s[-1] == "o" and s[-2] == "p":
        print("FILIPINO")
    elif s[-1] == "u" and s[-2] == "s" and s[-3] == "e" and s[-4] == "d":
        print("JAPANES")
    elif s[-1] == "u" and s[-2] == "s" and s[-3] == "a" and s[-4] == "m":
        print("JAPANES")
    elif s[-1] == "a" and s[-2] == "d" and s[-3] == "i" and s[-4] == "n" and s[-5] == "m":
        print("KOREAN")