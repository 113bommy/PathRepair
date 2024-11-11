num = int(input())
list1 = [1,1]
n = 0
while True:
    if list1[n] + list1[n+1] < num:
        list1.append(list1[n]+list1[n+1])
        n+=1
    else:
        break
string = ''
for i in range(1,num+1):
    if i in list1:string+='O'
    else: string+= 'o'
print(string)