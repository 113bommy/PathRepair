x = 100000
for i in range(int(input())):
    x*=1.05
    x+=999
    x=x//1000*1000
print(x)