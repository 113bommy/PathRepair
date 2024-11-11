T1 = input()
T2 = input()
h1 = int(T1[:2])
m1 = int(T1[3:])
h2 = int(T2[:2])
m2 = int(T2[3:])

h = (h2 - h1)//2
h3 =  (h2 - h1)/2
m = (m2 - m1)//2

H = h1 + h
M = m1 + m
#print("M:",M)
if M==60:
   M=0
   H+=1
if h3 - h ==0:
   H = "0"+str(H)
   M = "0"+str(M)
   if len(H)==3 and len(M)==3:
     print(H[1:]+":"+M[1:])
   elif len(H)==3 and len(M)==2:
     print(H[1:]+":"+M)
   elif len(H)==2 and len(M)==3:
     print(H+":"+M[1:])
   else:
     print(H+":"+M)
else:
   if M+30==60:
     M=0
     H+=1
   else:
     M+=30
   H = "0"+str(H)
   M = "0"+str(M)
   if len(H)==3 and len(M)==3:
     print(H[1:]+":"+M[1:])
   elif len(H)==3 and len(M)==2:
     print(H[1:]+":"+M)
   elif len(H)==2 and len(M)==3:
     print(H+":"+M[1:])
   else:
     print(H+":"+M)
   






