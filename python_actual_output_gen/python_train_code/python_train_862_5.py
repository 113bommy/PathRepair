n = int(input())
ai = input().replace(" ","")
num = ai.count("1")
print(num + ai.replace("101","1011").count("101"))

