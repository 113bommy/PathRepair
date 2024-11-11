n = int(input())

x = n
count = 0
for i in  range(1,(int((n/2+1)))):
    x = n
    x = x-i
    if(x%i == 0):
        count+=1

print(count)
