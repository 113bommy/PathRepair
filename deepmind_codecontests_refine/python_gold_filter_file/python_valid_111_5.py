import sys, os.path, math
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
 
###########################################
 
for t in range(int(input())):
    n = int(input())
    if(n == 1):
        print("()")
    elif(n == 2):
        print("()()")
        print("(())")
    else:
        for i in range(n):
            print("()", sep="", end = "")
        print()
        for i in range(n-1):
            for j in range(i):
                print("()", sep="",end="")
            print("(())", sep="",end="")
            for j in range(n-2-i):
                print("()", sep="",end="")
            print()