#Mapeo
d = {"0":"","1":"","2":"2","3":"3","4":"322","5":"5","6":"53","7":"7","8":"7222","9":"9"}
N=int(input())
A=input()
R=""
for k in range(N):
    R+=d[A[k]]
RR=sorted(R)
RR.reverse()
str1 = ''.join(RR)
print (str1)
