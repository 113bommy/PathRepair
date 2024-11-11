#ROUNIAAUDI
num1=int(input())
for i in range(num1):
    s=input().strip()
    if s.startswith("miao.")==True and s.endswith("lala.")==False:
        print("Rainbow's")
    elif s.startswith("miao.")==False and s.endswith("lala.")==True:

       print("Freda's")
    else:
        print("OMG>.< I don't know!")