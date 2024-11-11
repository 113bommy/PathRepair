x= input()
y = input().split()
l= []
for i in y:
    i = int(i)
    l.append(i)
k =0
for  i in l:
    if  i ==1:
        print('YES')
        k =1
        break
if k ==0:
    print("NO")
