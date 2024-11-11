a=input()
n=len('a')
for i in range(0,n):
            if ("0000000" in a or "1111111" in a):
                 print ("yes")
                 break
            else:
                 print("No")