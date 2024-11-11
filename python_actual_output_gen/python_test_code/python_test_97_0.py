oldie = {}
newie = {}

for I in range(int(input())):
    old,new = map(str,input().split())

    if old in newie:
        temp = newie[old]
        newie[new]=old
        oldie[temp]=new
        
    else:
        oldie[old]=new
        newie[new]=old

print(len(oldie))
for key,value in oldie.items():
    print(key,value)
