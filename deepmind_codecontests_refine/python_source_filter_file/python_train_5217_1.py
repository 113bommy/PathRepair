n = int(input())
r = n-10
if r<=0:
    print(0)
elif r==10:
    print(15)
elif r in range(1,21):
    print(4)
else:
    print(0)