a = input()
otv = int(len(a)/2)
if(not len(a)/2):
    if(a.count('1') > 1):
        otv+=1
print(otv)
