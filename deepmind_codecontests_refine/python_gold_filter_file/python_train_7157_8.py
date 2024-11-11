import math, sys
def dead():
    sys.stdout.write("-1")
    sys.exit()

debug = 0
if debug:
    f = open("input.txt", "r")
    input = f.readline
def main():
    a = input()
    b = list("BCA")
    for i in range(3):
        for j in range(3):
            for k in range(3):
                if i != j and j != k and i != k:
                    s = b[i] + b[j] + b[k]
                    if a.find(s) != -1:
                        print("Yes")
                        return
    print("No")
    
    
    
main()