m = int(input())
count=0
sign=["+"]

for i in range(0,m):
    s=input()
    if sign[0] in s :
        count = count + 2
    else :
        count = count -2    

print(count)