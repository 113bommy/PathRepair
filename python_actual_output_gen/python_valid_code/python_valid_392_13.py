n=int(input(),2)
a=4
for i in range(101):
    if n<=a:
        print(i+1)
        break
    a*=4
