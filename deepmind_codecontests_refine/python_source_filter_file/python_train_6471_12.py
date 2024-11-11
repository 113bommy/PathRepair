k = int(input())
s = ''
i = 1


while(len(s)<k):
    s += str(i)
    i+=1
    
print(s[-1])
