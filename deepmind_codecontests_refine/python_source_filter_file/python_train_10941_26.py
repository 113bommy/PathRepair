# inpt=input()
# l=inpt.split(" ")
# a=int(l[0])
# b=int(l[1])
# x=int(l[2])
# y=int(l[3])
# def prime(x,y):
#         for i in range(2,max(x,y)):
#                 while x%i==0 and y%i==0:
#                         x= x/i
#                         y= y/i
#         return [x,y]
# print (int(min(a/int(prime(x,y)[0]), b/int(prime(x,y)[1]))))


        


n=int(input())
l=[]
min_a=100001
min_b=100001
min_c=100001
min_abc=100001
def find(x,y):
    for i in x:
        if i==y:
            return True
for i in range(n):
    juice=input()
    l.append(juice.split())
for i in range(n):
    if l[i][1]=="A":
        if int(l[i][0])<min_a:
            min_a=int(l[i][0])
    elif l[i][1]=="B":
        if int(l[i][0])<min_b:
            min_b=int(l[i][0])
    elif l[i][1]=="C":
        if int(l[i][0])<min_c:
            min_c=int(l[i][0])
min1=100001
bad=True
for d in range(n):
    for c in range(n):
        all=l[d][1] + l[c][1]
        # print (all)
        if find(all, "A")==True and find(all,"B")==True and find(all,"C")==True:
            # print ("yaay")
            bad=False
            if min1> int(l[d][0])+ int(l[c][0]):
                min1=int(l[d][0])+ int(l[c][0])
if min_a!=100001 and min_b!=100001 and min_c!=100001:
    price=min_a + min_b + min_c
else:
    price=-1
for i in range(n):
    if find(l[i][1],"A")==True and find(l[i][1],"B")==True and find(l[i][1],"C")==True:
        if int(l[i][0])<min_abc:
            min_abc=int(l[i][0])

if min_abc!=100001 and bad==False and price!= -1:
    print(min(price,min_abc,min1))
elif min_abc!=100001 and bad==False:
    print(min(min_abc,min1))
elif bad==False and price!= -1:
    print(min(price,min1))
elif min_abc!=100001 and price!= -1:
    print(min(price,min_abc))
elif min_abc!=100001 :
    print(min_abc)
elif bad==False :
    print(min1)
elif price!= -1:
    print(price)
else:
    print("-1")

    