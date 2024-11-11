n = int(input())
huellas = input()
li = 1
ls = n
change_i = 0
change = False 
inicio = True
for i in range(1,n):
    if huellas[i] != "." and inicio:
        li = i
        inicio = False
    elif huellas[i] =="." and not inicio:
        ls = i
        inicio= True
    elif  huellas[i] != huellas[i-1] :
        change_i = i
        change = True

if change:
    print(li +1 , change)
elif huellas.find("R") > 0 :
    print(li+1 , ls +1) 
else: 
    print( ls, li )