n=int(input())
a=[]
for i in range(n):
    a.append(input())
for i in a:
    if len(i)<10:
        print(i)
    else:
        print("{}{}{}".format(i[0],len(i)-2,i[len(i)-1]))