from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    n=int(stdin.readline())
    arr=[int(k) for k in stdin.readline().split()]
    dic={}
    counter=0
    for i in range(n):
        if arr[i] not in dic:
            dic[arr[i]]=[i]
        else:
            dic[arr[i]].append(i)
    #print(dic)
    for i,j in dic.items():
        if len(j)>=2:
            #print(j[0])
            for k in range((len(j)-1)):
                if (j[k+1]-j[k])>=2:
                    counter=1
                    #print(k)
                    break
            
            
    if counter==1:   
        stdout.write("YES")
        stdout.write("\n")
    else:
        stdout.write("NO")
        stdout.write("\n")
    
            
    