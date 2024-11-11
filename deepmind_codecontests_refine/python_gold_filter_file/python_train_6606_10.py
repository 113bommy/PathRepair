import math
import sys

def nCr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)


st1 = input()
st2 = input()
plus1 = int(st1.count('+'))
plus2 = int(st2.count('+'))
minus1 = int(st1.count('-'))
minus2 = int(st2.count('-'))
ques2 = int(st2.count('?'))
ans1 = plus1-minus1
ans2 = plus2-minus2
if ques2==0:
    if ans1==ans2:
        print(1)
    else:
        print(0)
    sys.exit()

ans3 = int(ans1-ans2)
#print(ans3)
temp = ques2
for i in range(0,ques2+1):
    if (temp-i) == ans3:
        break
    temp=temp-1
#print(temp)
if temp-i != ans3:
    print(0)
    sys.exit()
value = int(nCr(ques2,temp))
#print(value)
print(value/pow(2,ques2))



