n = int(input())
x = input().split()
count = 0
for i in range(0,n):
    count = count + int(x[i])/100
a = ((count/n)*100)
print(round(a,12))
