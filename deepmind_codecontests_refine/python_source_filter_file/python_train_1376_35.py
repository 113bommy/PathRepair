x = int(input())

for i in range(x):
    string = str(input())
    result = ""
    maxNum = -1
    if(string.rfind("po")>=0):
        num = string.rfind("po")
        if(maxNum<num):
            maxNum=num
            result = "FILIPINO"
        
    if(string.rfind("desu")>=0):
        num = string.rfind("desu")
        if(maxNum<num):
            maxNum=num
            result = "JAPANESE"
    
    if(string.rfind("masu")>0):
        num = string.rfind("masu")
        if(maxNum<num):
            maxNum=num
            result = "JAPANESE"

    if(string.rfind("mnida")>=0):
        num = string.rfind("mnida")
        if(maxNum<num):
            maxNum=num
            result = "KOREAN"
    print(result)