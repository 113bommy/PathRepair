"""
the question is that we need to paint the pogo one letter at a time we need to design an lgorithm which helps
us accomplish this task in minimum effort as possible
ie dont move the ladder to more places many times

so the main thing to aim is to not overlap /use min overlapping as possible to do the task

my idea is that given a place ill see it the place is in the start or end
if so we have a clear path ir print char to right
or print char go left

else what we do is we go the nearest extreme and start from there
"""
def printfromLeft(string):
    for i in range(len(string)):
        print("PRINT {}".format(string[i]))
        if i<len(string)-1:
            print("RIGHT")
def printfromRight(string):
    for i in range(len(string)-1,-1,-1):
        print("PRINT {}".format(string[i]))
        if i>0:
            print("LEFT")
n,k=map(int,input().split())
logo=input()
if k==1:
    printfromLeft(logo)
elif k==len(logo):
    printfromRight(logo)
else:
    mid=len(logo)/2
    if k>=mid:
        for i in range(k,len(logo)):
            print("RIGHT")
        printfromRight(logo)
    else:
        for i in range(0,k):
            print("LEFT")
        printfromLeft(logo)
