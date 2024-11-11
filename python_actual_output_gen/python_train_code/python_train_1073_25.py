n=int(input())

a = input()

l = ['a','e','i','o','u','y']

x = list(a)

flag = 0

#for i in range(0,len(x)-1):
 #   if x[i] in l and x[i+1] in l:
  #      x.remove(i+1)
        
while True:
    if len(x)>1:
        for i in range(0,len(x)-1):
            if x[i] in l and x[i+1] in l:
                x.pop(i)
                flag = 1
                break
            else:
                if i==len(x) - 2:
                    flag = 0
                    break
            
    if flag==0 or len(x)==1:
        break
    
for i in range(0,len(x)):
    print(x[i],end='')    