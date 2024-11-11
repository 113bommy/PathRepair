# T = int(input())
# numbers = [int(s) for s in input().split(" ")]
# maxi = 0
# for i in range(0,len(numbers)):
#     lol = numbers.count(numbers[i])
#     if lol>maxi:
#         maxi = lol
#
# print(maxi)
a, b, x = [int(s) for s in input().split(" ")]
outputString = ""
length = a+b
while length>len(outputString):
    if len(outputString)==0:
        if a>0:
            a-=1
            x-=1
            outputString+="0"
        else:
            b -= 1
            x -= 1
            outputString += "1"
    while x>0:
        if outputString[len(outputString)-1]=="0":
            outputString+="1"
            b-=1
            x-=1
        else:
            outputString += "0"
            a-=1
            x-=1
    if outputString[len(outputString) - 1] == "0":
        while a>0:
            outputString += "0"
            a -= 1
        while b>0:
            outputString += "1"
            b -= 1
    else:
        while b>0:
            outputString += "1"
            b -= 1
        while a>0:
            outputString += "0"
            a -= 1
print(outputString)