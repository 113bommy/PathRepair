a=input()
b=a[1:].replace("C","")
c=b.lower()
print(["WA","AC"][a[0]=="A" and a[2:-2].count("C")==1 and b==c])