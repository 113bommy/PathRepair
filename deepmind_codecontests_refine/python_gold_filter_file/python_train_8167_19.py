fl = list(map(int, input().split()))
sl = list(map(int, input().split()))
myLocation = 1
# for i in range(1, fl[0]):
#     myLocation = myLocation+sl[myLocation-1]
#     if myLocation == fl[1]:
#         print("YES")
#         break
#     elif myLocation > fl[1]:
#         print("NO")
#         break
list = [1]
while myLocation <= len(sl):
    myLocation = myLocation+sl[myLocation-1]
    list.append(myLocation)
if fl[1] in list:
    print("YES")
else:
    print("NO")
