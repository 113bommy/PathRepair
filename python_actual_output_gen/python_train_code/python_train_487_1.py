n=int(input())
x=input().strip().split()
total=0
hand=0
for i in range(len(x)):
    total=total+int(x[i])

for j in range(5):
    j = j + 1

    if((total+j)% (n+1)==0):

        hand=hand+1

print(hand)
