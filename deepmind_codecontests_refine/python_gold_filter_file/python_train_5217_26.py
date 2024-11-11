n=int(input())
li={}
li[10]=15
card=n-10
if card<=0:
    print(0)
elif card>11:
    print(0)
elif card==10:
    print(15)
else:
    print(4)