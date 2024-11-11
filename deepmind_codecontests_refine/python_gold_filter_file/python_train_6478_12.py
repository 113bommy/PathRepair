l=int(input())
a=input()
a.replace(" ", "")
b=input()
b.replace(" ", "")
#print(a,b)
c_i,val = 0,0
for i in range(len(a)):
    #print(i)
    #print(a[i],b[i])
    if b[i] == "1" and a[i] == "0":
        c_i += 1
        #print(c_i)
    if b[i] == "0" and a[i] == "1":
        val += 1

#print(c_i,val)

if val > c_i:
    print("1")
elif val <=c_i and val!= 0:
    if c_i % val == 0:
        print(int(c_i//val)+1)
    if c_i % val != 0:
        print(int(c_i//val)+1)
else:
    print("-1")
