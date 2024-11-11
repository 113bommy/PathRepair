n=int(input())
s=input()
i=0
s2="ogo"+"go"*(n//2)
while s2 != "ogo":
    s=s.replace(s2,"***")
    s2=s2[:-2]
print(s)