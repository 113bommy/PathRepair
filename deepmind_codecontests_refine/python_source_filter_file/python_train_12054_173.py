a = int(input())
b=0
for i in range(a):
    if i%3!=0 and i%5!=0:
        b+=i
print(b)