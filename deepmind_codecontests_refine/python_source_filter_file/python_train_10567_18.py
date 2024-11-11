string=input()
quantity=int(input())
for i in range(quantity):
    act=input().split()
    start=int(act[0])-1
    finish=int(act[1])
    shift=int(act[2])
    subString=string[start:finish]
    shift=shift%len(subString)
    subString=subString[-shift]+subString[0:-shift]
    string=string[:start]+subString+string[finish:]
print (string)
