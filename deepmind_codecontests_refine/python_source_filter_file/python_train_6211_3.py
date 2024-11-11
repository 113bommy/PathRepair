def fun(str):
    list = str.split('/')
    dem = int(list[1])
    list = list[0]
    list = list[1:-1]
    list1 = list.split('+')
    num = int(list1[0]) + int(list1[1])
    return num//dem

dict = {}
list = []
n = int(input())
while( n != 0):
    n = n-1
    str = input()
    ans = fun(str)
    if ans in dict:
        dict[ans] = dict[ans]+1
    else:
        dict[ans] = 1
    list.append(ans)

for i in range(len(list)):
    print (dict[list[i]], end=" ")
