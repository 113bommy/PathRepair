a=input()
a=str(a.count("4")+a.count("7"))
x=(a.count("4")+a.count("7"))==len(a)
print(["NO","Yes"][x])
