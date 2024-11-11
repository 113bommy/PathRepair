import sys

a, b, x = (map(int, sys.stdin.readline().split()))
out = ""
diff = ""
if x% 2 == 1:
    i = "0"
    for loop in range(x+1):
        diff += i
        if i == "1":
            i = "0"
        else:
            i = "1"
    for loop in range(a-(x+1)//2):
        out += "0"
    out += diff
    for loop in range(b-(x+1)//2):
        out += "1"
if x% 2 == 0:
    if a > b:
        diff = "01" + "1"*(b-x//2) + "01" *(x//2-1)+ "0" + "0"*((a-x//2)-1)
        out = diff
    else:
        diff = "10" + "0"*(b-x//2) + ("10")*(x//2-1)+ "1" + "1"*((a-x//2)-1)
        out = diff
print(out)
    


        