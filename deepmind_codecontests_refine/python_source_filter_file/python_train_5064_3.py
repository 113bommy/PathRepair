#input
n=int(input())

a=[]
for i in range(0,n):
    a.append(input())

#calculation
noise=0

def calc_noise(str):
    result = 0
    
    struct =[]  
    struct.append(0)
    c = "s"
    j = 0
    str.lstrip("h")
    for i in range(0,len(str)):
        if str[i]==c:
            struct[j] +=  1
        else:
            c = str[i]
            struct.append(1)
            j += 1
    
    s = 0
    for i in range(0, len(struct)):
        if i%2!=0:
            result += s*struct[i]
        else:
            s += struct[i]
    return result        
    

v=[]
for i in range(0,n):
    cs=a[i].count("s")
    ch=len(a[i]) - cs
    sound = calc_noise(a[i])
    if cs==0:
        v.append([i,-100000, 0])
    else:
        if ch==0:
            v.append([i,100000, 0])
        else:
            v.append([i,cs - ch, sound])
            
v.sort(key=lambda x: x[2], reverse=1)             
v.sort(key=lambda x: x[1], reverse=1)      

str = ""
for i in range(0,n):
    str += a[v[i][0]] 
noise = calc_noise(str)
    
#output

print(noise)